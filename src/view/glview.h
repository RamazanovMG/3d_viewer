/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file glview.h
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#ifndef CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_

#include <QFloat16>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <vector>

#include "../controller/controller.h"

namespace s21 {

#define kWidth 800
#define kHeight 560
#define kOrtho 4.0f

class IObserver {
 public:
  virtual void UpdateStatusBar(const QString &message) = 0;
};

class IObservable {
 public:
  virtual void AddObserver(IObserver *other) = 0;
  virtual void RemoveObserver(IObserver *other) = 0;
  virtual void NotifyStatusBar(const QString &status_message) = 0;
  virtual ~IObservable() {}
};

class GlView : public QOpenGLWidget, public IObservable {
  Q_OBJECT

 public:
  explicit GlView(QWidget *parent = nullptr);

  int GetOrtho() const noexcept { return ortho_; }
  void SetOrtho(int ortho) noexcept { ortho_ = ortho; }
  void SetLineWidth(quint8 width) noexcept { line_width_ = width; };
  void SetPointWidth(quint8 width) noexcept { point_width_ = width; };
  int GetDrawStyle() const noexcept { return draw_style_; }
  void SetDrawStyle(int draw_style) noexcept { draw_style_ = draw_style; }
  int GetPointRound() const noexcept { return point_round_; }
  void SetPointRound(int point_round) noexcept { point_round_ = point_round; }
  QColor *GetBgColor() noexcept { return &bg_color_; }
  void SetBgColor(QColor bg_color) noexcept { bg_color_ = bg_color; }
  QColor *GetLineColor() noexcept { return &line_color_; }
  void SetLineColor(QColor line_color) noexcept { line_color_ = line_color; }
  QColor *GetPointColor() noexcept { return &point_color_; }
  void SetPointColor(QColor point_color) noexcept {
    point_color_ = point_color;
  }
  void SetController(Controller *controller) { controller_ = controller; }
  Controller *GetController() { return controller_; }

  void OpenFile(char *filename);

  void AddObserver(IObserver *other) override { observers_.push_back(other); }
  void RemoveObserver(IObserver *other) override {
    observers_.erase(remove(observers_.begin(), observers_.end(), other),
                     observers_.end());
  }
  void NotifyStatusBar(const QString &status_message) override {
    for (auto other : observers_) {
      other->UpdateStatusBar(status_message);
    }
  }

 private:
  std::vector<IObserver *> observers_;
  Controller *controller_;

  int ortho_;
  quint8 line_width_;
  quint8 point_width_;
  quint8 draw_style_;
  quint8 point_round_;
  QColor bg_color_;
  QColor line_color_;
  QColor point_color_;

  float left_;
  float right_;
  float bottom_;
  float top_;

  QPoint last_mouse_position_;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *) override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void UpdateStatusBarText(QString text);
  void DrawLineView();
  void DrawPointView();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_VIEW_GLVIEW_H_
