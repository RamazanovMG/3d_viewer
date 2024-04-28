/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file joystick.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include "joystick.h"

namespace s21 {

void MoveStrategy::ConfigureUI(Ui::MainWindow* ui) {
  ui->buttonUp->setVisible(true);
  ui->buttonDown->setVisible(true);
  ui->buttonRight->setVisible(true);
  ui->buttonLeft->setVisible(true);
  ui->buttonZ1->setVisible(true);
  ui->buttonZ2->setVisible(true);
  ui->buttonUp->setText("↑");
  ui->buttonDown->setText("↓");
  ui->buttonZ1->setText("+");
  ui->buttonZ2->setText("-");
}

void RotateStrategy::ConfigureUI(Ui::MainWindow* ui) {
  ui->buttonUp->setVisible(true);
  ui->buttonDown->setVisible(true);
  ui->buttonRight->setVisible(true);
  ui->buttonLeft->setVisible(true);
  ui->buttonZ1->setVisible(true);
  ui->buttonZ2->setVisible(true);
  ui->buttonUp->setText("↑");
  ui->buttonDown->setText("↓");
  ui->buttonZ1->setText("↻");
  ui->buttonZ2->setText("↺");
}

void ZoomStrategy::ConfigureUI(Ui::MainWindow* ui) {
  ui->buttonLeft->setVisible(false);
  ui->buttonRight->setVisible(false);
  ui->buttonZ1->setVisible(false);
  ui->buttonZ2->setVisible(false);
  ui->buttonUp->setText("+");
  ui->buttonDown->setText("-");
}

}  // namespace s21
