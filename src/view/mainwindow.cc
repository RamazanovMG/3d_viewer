/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file mainwindow.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include "mainwindow.h"

#include <qgifimage.h>

#include <QColorDialog>
#include <QElapsedTimer>
#include <QTimer>

#include "../model/model.h"
#include "glview.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  gl_view_ = new GlView(this);
  settings_ = new QSettings("settings.ini", QSettings::IniFormat, this);
  LoadSettings();

  gl_view_->move(0, 0);
  gl_view_->resize(800, 600);
  gl_view_->show();
  count_ = 0;
  screen_folder_ = "/";
  // Уникальный идентификатор выбора текущего состояния джойстика.
  ui_->buttonGroup->addButton(ui_->radioButtonMove, 1);
  ui_->buttonGroup->addButton(ui_->radioButtonRotate, 2);
  ui_->buttonGroup->addButton(ui_->radioButtonZoom, 3);

  // Создаем объект стратегии для начального состояния (MoveStrategy)
  IJoystick *initialJoystickStrategy = new MoveStrategy;
  // Устанавливаем эту стратегию
  setJoystickStrategy(initialJoystickStrategy);
  gl_view_->AddObserver(this);
}

MainWindow::~MainWindow() { delete ui_; }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                     SETTINGS                     */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::LoadSettings() {
  gl_view_->SetOrtho(settings_->value("ortho", "1").toInt());
  // Устанавливаем значение
  ui_->checkBoxOrtho->setChecked(gl_view_->GetOrtho());

  gl_view_->SetDrawStyle(settings_->value("draw_style", "0").toInt());
  // Устанавливаем значение
  switch (gl_view_->GetDrawStyle()) {
    case 0:
      ui_->radioButtonSolid->setChecked(1);
      break;
    case 1:
      ui_->radioButtonStripple->setChecked(1);
      break;
    case 2:
      ui_->radioButtonPoint->setChecked(1);
      break;
    default:
      break;
  }

  ui_->spinBoxLineWidth->setValue(settings_->value("line_width", "0").toInt());

  gl_view_->GetLineColor()->setNamedColor(
      settings_->value("line_color", "#ffffff").toString());
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->frameLineColor->setStyleSheet(
      "background-color: " + gl_view_->GetLineColor()->name(QColor::HexRgb) +
      ";");

  ui_->spinBoxPointWidth->setValue(
      settings_->value("point_width", "0").toInt());

  gl_view_->GetPointColor()->setNamedColor(
      settings_->value("point_color", "#ffffff").toString());
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->framePointColor->setStyleSheet(
      "background-color: " + gl_view_->GetPointColor()->name(QColor::HexRgb) +
      ";");

  gl_view_->GetBgColor()->setNamedColor(
      settings_->value("background_color", "#000000").toString());
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->frameBFColor->setStyleSheet(
      "background-color: " + gl_view_->GetBgColor()->name(QColor::HexRgb) +
      ";");

  gl_view_->SetPointRound(settings_->value("point_rounded", "0").toInt());
  ui_->checkBoxRound->setChecked(gl_view_->GetPointRound());

  ui_->spinBoxStep->setValue(settings_->value("joy_step_move", "100").toInt());
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                      OTHERS                      */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool MainWindow::ChoiceScreenFolder() {
  bool error = 0;
  screen_folder_ = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "~",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  if (screen_folder_.isEmpty() && screen_folder_.isNull())
    error = 1;
  else
    ui_->statusBar->showMessage(screen_folder_, 3000);

  return error;
}

void MainWindow::UpdateFrames() {
  if (count_ == 50) {
    QGifImage gif(QSize(640, 480));
    gif.setDefaultDelay(100);
    for (int i = 0; i < 50; i++) gif.addFrame(frames_[i]);
    gif.save(screen_folder_ + "/screencast_" + getTimeNow() + ".gif");
    timer_->stop();
  } else {
    QPixmap pixmap = gl_view_->grab();
    QImage image = pixmap.toImage();
    image = image.scaled(640, 480);
    frames_[count_] = (image);
    count_++;
  }
}

QString MainWindow::getTimeNow() {
  QDateTime date = QDateTime::currentDateTime();
  return date.toString("dd_MM_yyyy_hh_mm_ss");
}

void MainWindow::UpdateStatusBar(const QString &status_message) {
  ui_->statusBar->showMessage(status_message);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                RADIO/CHECK BLOCK                 */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_checkBoxOrtho_stateChanged(int arg1) {
  gl_view_->SetOrtho(arg1);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("ortho", gl_view_->GetOrtho());
}

void MainWindow::on_radioButtonSolid_toggled(bool checked) {
  gl_view_->SetDrawStyle(0);
  if (checked) ui_->statusBar->showMessage("Draw style: Solid", 3000);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("draw_style", gl_view_->GetDrawStyle());
}

void MainWindow::on_radioButtonStripple_toggled(bool checked) {
  gl_view_->SetDrawStyle(1);
  if (checked) ui_->statusBar->showMessage("Draw style: Stripple", 3000);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("draw_style", gl_view_->GetDrawStyle());
}

void MainWindow::on_radioButtonPoint_toggled(bool checked) {
  gl_view_->SetDrawStyle(2);
  if (checked) ui_->statusBar->showMessage("Draw style: Points", 3000);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("draw_style", gl_view_->GetDrawStyle());
}

void MainWindow::on_checkBoxRound_stateChanged(int arg1) {
  gl_view_->SetPointRound(arg1);
  ui_->statusBar->showMessage("Point rounded: " + QString::number(arg1), 3000);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("point_rounded", gl_view_->GetPointRound());
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                 SPIN BOX BLOCK                   */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_spinBoxLineWidth_valueChanged(int arg1) {
  ui_->statusBar->showMessage("Line width: " + QString::number(arg1), 3000);
  gl_view_->SetLineWidth(arg1);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("line_width", arg1);
}

void MainWindow::on_spinBoxPointWidth_valueChanged(int arg1) {
  ui_->statusBar->showMessage("Point width: " + QString::number(arg1), 3000);
  gl_view_->SetPointWidth(arg1);
  gl_view_->update();
  // Сохраняем значение в settings.ini
  settings_->setValue("point_width", arg1);
}
void MainWindow::on_spinBoxStep_valueChanged(int arg1) {
  ui_->statusBar->showMessage("Step: " + QString::number(arg1), 3000);
  // Сохраняем значение в settings.ini
  if (ui_->radioButtonMove->isChecked())
    settings_->setValue("joy_step_move", arg1);
  if (ui_->radioButtonRotate->isChecked())
    settings_->setValue("joy_step_rotate", arg1);
  if (ui_->radioButtonZoom->isChecked())
    settings_->setValue("joy_step_zoom", arg1);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                  BUTTON BLOCK                    */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_buttonOpen_clicked() {
  QString filename = QFileDialog::getOpenFileName();
  if (!filename.isEmpty()) {
    QByteArray ba = filename.toLocal8Bit();
    QElapsedTimer timer;
    timer.start();
    gl_view_->OpenFile(ba.data());
    ui_->statusBar->showMessage(
        filename + " [open time:" + QString::number(timer.elapsed()) + "ms" +
        ", vertex: " +
        QString::number(gl_view_->GetController()->GetNumberOfVertices()) +
        ", poligons: " +
        QString::number(gl_view_->GetController()->GetNumberOfPolygons()) +
        "]");
  }
}

void MainWindow::on_buttonBmp_clicked() {
  if (!ChoiceScreenFolder()) {
    QPixmap pixmap = gl_view_->grab();
    QFile file(screen_folder_ + "/screenshot_" + getTimeNow() + ".bmp");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "BMP");
  }
}

void MainWindow::on_buttonJpg_clicked() {
  if (!ChoiceScreenFolder()) {
    QPixmap pixmap = gl_view_->grab();
    QFile file(screen_folder_ + "/screenshot_" + getTimeNow() + ".jpeg");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "JPEG");
  }
}

void MainWindow::on_buttonGif_clicked() {
  if (!ChoiceScreenFolder()) {
    count_ = 0;
    timer_ = new QTimer();
    timer_->start(100);
    connect(timer_, SIGNAL(timeout()), this, SLOT(UpdateFrames()));
  }
}

void MainWindow::on_buttonBGColor_clicked() {
  gl_view_->SetBgColor(QColorDialog::getColor(Qt::white, this));
  // Сохраняем значение в settings.ini
  settings_->setValue("background_color",
                      gl_view_->GetBgColor()->name(QColor::HexRgb));
  QString style_sheet =
      "background-color: " + gl_view_->GetBgColor()->name(QColor::HexRgb) + ";";
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->frameBFColor->setStyleSheet(style_sheet);
  //  Выводим информацию о цвете в статусную строку
  ui_->statusBar->showMessage(style_sheet, 5000);
}

void MainWindow::on_buttonLineColor_clicked() {
  gl_view_->SetLineColor(QColorDialog::getColor(Qt::white, this));
  // Сохраняем значение в settings.ini
  settings_->setValue("line_color",
                      gl_view_->GetLineColor()->name(QColor::HexRgb));
  QString style_sheet =
      "background-color: " + gl_view_->GetLineColor()->name(QColor::HexRgb) +
      ";";
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->frameLineColor->setStyleSheet(style_sheet);
  //  Выводим информацию о цвете в статусную строку
  ui_->statusBar->showMessage(style_sheet, 5000);
}

void MainWindow::on_buttonPointColor_clicked() {
  gl_view_->SetPointColor(QColorDialog::getColor(Qt::white, this));
  // Сохраняем значение в settings.ini
  settings_->setValue("point_color",
                      gl_view_->GetPointColor()->name(QColor::HexRgb));
  QString style_sheet =
      "background-color: " + gl_view_->GetPointColor()->name(QColor::HexRgb) +
      ";";
  // Устанавливаем цвет квадрата рядом с кнопкой
  ui_->framePointColor->setStyleSheet(style_sheet);
  //  Выводим информацию о цвете в статусную строку
  ui_->statusBar->showMessage(style_sheet, 5000);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                     JOYSTICK                     */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_radioButtonMove_toggled(bool checked) {
  if (checked) {
    setJoystickStrategy(new MoveStrategy);
    ui_->spinBoxStep->setValue(
        settings_->value("joy_step_move", "100").toInt());
  }
}

void MainWindow::on_radioButtonRotate_toggled(bool checked) {
  if (checked) {
    setJoystickStrategy(new RotateStrategy);
    ui_->spinBoxStep->setValue(
        settings_->value("joy_step_rotate", "100").toInt());
  }
}

void MainWindow::on_radioButtonZoom_toggled(bool checked) {
  if (checked) {
    setJoystickStrategy(new ZoomStrategy);
    ui_->spinBoxStep->setValue(
        settings_->value("joy_step_zoom", "100").toInt());
  }
}

void MainWindow::on_buttonUp_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(ui_->spinBoxStep->value(), 1);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(-ui_->spinBoxStep->value(), 0);
  if (ui_->radioButtonZoom->isChecked())
    gl_view_->GetController()->Scale(ui_->spinBoxStep->value() / 10.0);
  gl_view_->update();
}

void MainWindow::on_buttonDown_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(-ui_->spinBoxStep->value(), 1);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(ui_->spinBoxStep->value(), 0);
  if (ui_->radioButtonZoom->isChecked())
    gl_view_->GetController()->Scale(-ui_->spinBoxStep->value() / 10.0);
  gl_view_->update();
}

void MainWindow::on_buttonLeft_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(-ui_->spinBoxStep->value(), 0);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(ui_->spinBoxStep->value(), 1);
  gl_view_->update();
}

void MainWindow::on_buttonRight_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(ui_->spinBoxStep->value(), 0);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(-ui_->spinBoxStep->value(), 1);
  gl_view_->update();
}

void MainWindow::on_buttonZ1_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(ui_->spinBoxStep->value(), 2);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(ui_->spinBoxStep->value(), 2);
  gl_view_->update();
}

void MainWindow::on_buttonZ2_clicked() {
  if (ui_->radioButtonMove->isChecked())
    gl_view_->GetController()->Shift(-ui_->spinBoxStep->value(), 2);
  if (ui_->radioButtonRotate->isChecked())
    gl_view_->GetController()->Rotate(-ui_->spinBoxStep->value(), 2);
  gl_view_->update();
}
}  // namespace s21
