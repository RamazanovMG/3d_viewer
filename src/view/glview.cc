/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file glview.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include "glview.h"

namespace s21 {

GlView::GlView(QWidget *parent)
    : QOpenGLWidget(parent),
      ortho_(0),
      line_width_(0),
      point_width_(0),
      draw_style_(0),
      point_round_(0) {
  left_ = -1.0 * kWidth / kHeight;
  right_ = 1.0 * kWidth / kHeight;
  bottom_ = -1.0;
  top_ = 1.0;
}

void GlView::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glLineStipple(1, 0x00FF);  // Маска пунктирной линии
}

void GlView::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void GlView::paintGL() {
  glClearColor(bg_color_.redF(), bg_color_.greenF(), bg_color_.blueF(),
               bg_color_.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (ortho_)
    glOrtho(left_ * kOrtho, right_ * kOrtho, bottom_ * kOrtho, top_ * kOrtho,
            -100.0, 100.0);
  else
    glFrustum(left_, right_, bottom_, top_, 1, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3);

  if (draw_style_ == 2) {
    DrawPointView();
  } else {
    DrawLineView();
  }
}

// Тип отображения: линии
void GlView::DrawLineView() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  draw_style_ ? glEnable(GL_LINE_STIPPLE) : glDisable(GL_LINE_STIPPLE);

  glLineWidth(line_width_);

  GLfloat color[] = {line_color_.redF(), line_color_.greenF(),
                     line_color_.blueF(), line_color_.alphaF()};

  glColor4fv(color);
  
  glVertexPointer(3, GL_DOUBLE, 0, GetController()->GetVertices());
  glEnableClientState(GL_VERTEX_ARRAY);

  for (unsigned int i = 0; i < GetController()->GetNumberOfPolygons(); i++) {
    glDrawElements(GL_LINES, GetController()->GetPolygons()[i].polygon_size_,
                   GL_UNSIGNED_INT,
                   GetController()->GetPolygons()[i].polygon_vertices_);
  }
}

// Тип отображения: точки
void GlView::DrawPointView() {
  glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

  if (point_round_) {
    glDisable(GL_POINT);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  } else {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT);
  }

  glPointSize(point_width_);

  GLfloat color[] = {point_color_.redF(), point_color_.greenF(),
                     point_color_.blueF(), point_color_.alphaF()};
  glColor4fv(color);
  
  glVertexPointer(3, GL_DOUBLE, 0, GetController()->GetVertices());
  glEnableClientState(GL_VERTEX_ARRAY);

  for (unsigned int i = 0; i < GetController()->GetNumberOfPolygons(); i++) {
    glDrawElements(GL_POINTS, GetController()->GetPolygons()[i].polygon_size_,
                   GL_UNSIGNED_INT,
                   GetController()->GetPolygons()[i].polygon_vertices_);
  }

  glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                       EVENTS                         */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void GlView::mousePressEvent(QMouseEvent *mouseEvent) {
  last_mouse_position_ = mouseEvent->pos();
  if (mouseEvent->button() == Qt::RightButton) {
    UpdateStatusBarText(" [right] ");
    update();
  }
}

void GlView::mouseMoveEvent(QMouseEvent *mouseEvent) {
  if (mouseEvent->buttons() == Qt::LeftButton) {
    UpdateStatusBarText(" [rotate] " + QString::number(mouseEvent->pos().x()) +
                        " : " + QString::number(mouseEvent->pos().y()));
    GetController()->Rotate(
        static_cast<double>(mouseEvent->pos().y() - last_mouse_position_.y()),
        0);
    GetController()->Rotate(
        static_cast<double>(last_mouse_position_.x() - mouseEvent->pos().x()),
        1);
    update();
  } else if (mouseEvent->buttons() == Qt::MiddleButton) {
    UpdateStatusBarText(" [move] " + QString::number(mouseEvent->pos().x()) +
                        " : " + QString::number(mouseEvent->pos().y()));

    GetController()->Shift(10 * static_cast<double>(mouseEvent->pos().x() -
                                                    last_mouse_position_.x()),
                           0);
    GetController()->Shift(10 * static_cast<double>(last_mouse_position_.y() -
                                                    mouseEvent->pos().y()),
                           1);
  }

  last_mouse_position_ = mouseEvent->pos();
  update();
}

void GlView::wheelEvent(QWheelEvent *wheelEvent) {
  QString str;
  int step = wheelEvent->angleDelta().y();
  if (step > 0) {
    str = "in";
    GetController()->Scale(5);
  } else {
    str = "out";
    GetController()->Scale(-5);
  }
  UpdateStatusBarText(" [zoom " + str + "] : " + QString::number(step));
  update();
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                      HELPERS                         */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// void GlView::updateStatusBarText(QString text) { emit signalTextToForm(text);
// }
void GlView::UpdateStatusBarText(QString text) { NotifyStatusBar(text); }

// ToDo: Переносим в контроллер.
void GlView::OpenFile(char *filename) {
  try {
    GetController()->OpenFile(filename);
  } catch (const std::invalid_argument &fail) {
    QMessageBox::critical(nullptr, "Error open file", fail.what());
    qDebug() << fail.what();
  } catch (const std::ios_base::failure &fail) {
    QMessageBox::critical(nullptr, "Error open file", fail.what());
    qDebug() << fail.what();
  } catch (const std::out_of_range &fail) {
    QMessageBox::critical(nullptr, "Error open file", fail.what());
    qDebug() << fail.what();
  }
}
}  // namespace s21
