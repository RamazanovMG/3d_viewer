/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file main.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include <QApplication>

#include "../controller/controller.h"
#include "../model/model.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::Controller controller(&s21::Model::GetInstance());
  QApplication a(argc, argv);
  s21::MainWindow w;
  w.SetController(&controller);
  w.setWindowIcon(QIcon(":/icon/i2.png"));
  w.setWindowTitle("3D Viewer v2.0 (written by PhylisCr, MorrisRo)");
  w.setGeometry(100, 100, 800, 600);
  w.show();
  return a.exec();
}
