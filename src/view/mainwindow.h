/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file mainwindow.h
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#ifndef CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>

#include "glview.h"
#include "joystick.h"

namespace s21 {

class MainWindow : public QMainWindow, public IObserver {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void LoadSettings();
  bool ChoiceScreenFolder();
  QSettings *GetSettings() { return settings_; };
  void UpdateStatusBar(const QString &message) override;
  inline void setJoystickStrategy(IJoystick *strategy) {
    this->currentJoystickStrategy_ = strategy;
    currentJoystickStrategy_->ConfigureUI(ui_);
  }
  void SetController(Controller *controller) {
    gl_view_->SetController(controller);
  }

 private:
  Ui::MainWindow *ui_;
  GlView *gl_view_;
  QSettings *settings_;
  QColor color_;
  IJoystick *currentJoystickStrategy_;
  QTimer *timer_;
  QImage frames_[50];
  QString screen_folder_;
  int count_;

  QString getTimeNow();

  // public slots:
  //  void slotTextFromGlView(const QString &message);

 private slots:
  void on_checkBoxOrtho_stateChanged(int arg1);
  void on_radioButtonSolid_toggled(bool checked);
  void on_radioButtonStripple_toggled(bool checked);
  void on_radioButtonPoint_toggled(bool checked);
  void on_checkBoxRound_stateChanged(int arg1);

  void on_spinBoxLineWidth_valueChanged(int arg1);
  void on_spinBoxPointWidth_valueChanged(int arg1);
  void on_spinBoxStep_valueChanged(int arg1);

  void on_buttonOpen_clicked();
  void on_buttonBmp_clicked();
  void on_buttonJpg_clicked();
  void on_buttonGif_clicked();
  void on_buttonBGColor_clicked();
  void on_buttonLineColor_clicked();
  void on_buttonPointColor_clicked();

  void on_radioButtonMove_toggled(bool checked);
  void on_radioButtonRotate_toggled(bool checked);
  void on_radioButtonZoom_toggled(bool checked);

  void on_buttonUp_clicked();
  void on_buttonDown_clicked();
  void on_buttonLeft_clicked();
  void on_buttonRight_clicked();
  void on_buttonZ1_clicked();
  void on_buttonZ2_clicked();

  void UpdateFrames();
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
