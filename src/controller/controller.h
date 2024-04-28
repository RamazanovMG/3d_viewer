/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file controller.h
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#ifndef CPP4_3DVIEWER_v2_0_CONTROLLER_CONTROLLER_H
#define CPP4_3DVIEWER_v2_0_CONTROLLER_CONTROLLER_H

#include <string>

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  explicit Controller(Model* m) : model_(m) {}
  Controller(const Controller& other) = delete;
  Controller& operator=(const Controller& other) = delete;
  ~Controller() {}

  void OpenFile(const std::string&);
  void Shift(double, int);
  void Scale(double);
  void Rotate(double, int);

  double* GetVertices() const noexcept;
  unsigned int GetNumberOfVertices() const noexcept;
  Model::Polygon* GetPolygons() const noexcept;
  unsigned int GetNumberOfPolygons() const noexcept;

 private:
  Model* model_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_v2_0_CONTROLLER_CONTROLLER_H
