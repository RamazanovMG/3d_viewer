/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file controller.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include "controller.h"

namespace s21 {
void Controller::OpenFile(const std::string& filename) {
  Model::GetInstance().ParseObjFile(filename);
  Model::GetInstance().CenterAndNormalize();
}

void Controller::Shift(double value, int axis) {
  Model::GetInstance().Shift(value, axis);
}

void Controller::Scale(double value) { Model::GetInstance().Scale(value); }

void Controller::Rotate(double angle, int axis) {
  Model::GetInstance().Rotate(angle, axis);
}

double* Controller::GetVertices() const noexcept {
  return Model::GetInstance().GetVertices();
}

unsigned int Controller::GetNumberOfVertices() const noexcept {
  return Model::GetInstance().GetNumberOfVertices();
}

Model::Polygon* Controller::GetPolygons() const noexcept {
  return Model::GetInstance().GetPolygons();
}

unsigned int Controller::GetNumberOfPolygons() const noexcept {
  return Model::GetInstance().GetNumberOfPolygons();
}
}  // namespace s21
