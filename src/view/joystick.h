/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Модель для основного задания, калькулятор с построением графиков.
 * @file joystick.h
 * @date 2023-08-31
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#ifndef CPP4_3DVIEWER_V2_0_VIEW_JOYSTICK_H_
#define CPP4_3DVIEWER_V2_0_VIEW_JOYSTICK_H_

#include <QMainWindow>

#include "ui_mainwindow.h"

namespace s21 {

class IJoystick {
 public:
  virtual void ConfigureUI(Ui::MainWindow* ui) = 0;
};

class MoveStrategy : public IJoystick {
 public:
  void ConfigureUI(Ui::MainWindow* ui) override;
};

class RotateStrategy : public IJoystick {
 public:
  void ConfigureUI(Ui::MainWindow* ui) override;
};

class ZoomStrategy : public IJoystick {
 public:
  void ConfigureUI(Ui::MainWindow* ui) override;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_JOYSTICK_H_
