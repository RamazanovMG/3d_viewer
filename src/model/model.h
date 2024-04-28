/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file model.h
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#ifndef CPP4_3DVIEWER_v2_0_MODEL_MODEL_H
#define CPP4_3DVIEWER_v2_0_MODEL_MODEL_H

#include <string>
const double kRatio = 0.001;

namespace s21 {
class Model {
 public:
  static Model& GetInstance() {
    static Model model_instance_;
    return model_instance_;
  }

  ~Model() {
    delete[] vertices_;
    for (size_t i = 0; i < number_of_polygons_; ++i)
      delete[] polygons_[i].polygon_vertices_;
    delete[] polygons_;
  }

  void ParseObjFile(const std::string&);
  void CenterAndNormalize();

  void Shift(double, int);
  void Scale(double);
  void Rotate(double, int);

  struct Polygon {
    unsigned int* polygon_vertices_;
    unsigned int polygon_size_;
  };

  inline double* GetVertices() const noexcept { return vertices_; }
  inline unsigned int GetNumberOfVertices() const noexcept {
    return number_of_vertices_;
  }
  inline Polygon* GetPolygons() const noexcept { return polygons_; }
  inline unsigned int GetNumberOfPolygons() const noexcept {
    return number_of_polygons_;
  }

 private:
  Model()
      : number_of_vertices_(0),
        vertices_(nullptr),
        number_of_polygons_(0),
        polygons_(nullptr) {}
  Model(const Model&) = delete;
  Model& operator=(Model&) = delete;

  unsigned int number_of_vertices_;
  double* vertices_;
  unsigned int number_of_polygons_;
  Polygon* polygons_;
  double extrema_[6] = {};

  void ReadVertices(const std::string&, unsigned int&);
  void ReadPolygon(const std::string&, unsigned int&, const unsigned int&);
  void SetExtrema();
  void CountVertices(const std::string&);
  void ClearData();

  void RotateOx(double);
  void RotateOy(double);
  void RotateOz(double);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_v2_0_MODEL_MODEL_H
