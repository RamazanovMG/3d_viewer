
/*******************************************************************************
 * @copyright Copyright [2023] <Phylis Cristobal, Morris Roggo>
 * @brief Разработать программу 3DViewer v2.0.
 * @file model.cc
 * @date 2023-08-28
 * @author Morris Roggo, Phylis Cristobal
 ********************************************************************************/

#include "model.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <utility>

namespace s21 {

void Model::ParseObjFile(const std::string& filename) {
  std::setlocale(LC_ALL, "en_US.UTF-8");
  std::ifstream obj_file(filename);
  number_of_vertices_ = 0;
  vertices_ = nullptr;
  number_of_polygons_ = 0;
  polygons_ = nullptr;

  if (!obj_file) {
    throw std::ifstream::failure("Cannot open specified file");
  } else {
    std::string line;
    while (std::getline(obj_file, line)) {
      if (line.size() < 2)
        continue;
      else if (line.at(0) == 'v' && line.at(1) == ' ')
        CountVertices(line);
      else if (line.at(0) == 'f')
        ++number_of_polygons_;
    }
    if (number_of_vertices_ == 0) {
      number_of_polygons_ = 0;
      throw std::invalid_argument("File contains no vertices");
    }
    ClearData();
    vertices_ = new double[number_of_vertices_];
    polygons_ = new Polygon[number_of_polygons_];
    unsigned int vertices_counter_ = 0;
    unsigned int polygons_counter_ = 0;
    obj_file.clear();
    obj_file.seekg(0);
    while (std::getline(obj_file, line)) {
      if (line.size() < 2)
        continue;
      else if (line.at(0) == 'v' && line.at(1) == ' ')
        ReadVertices(line, vertices_counter_);
      else if (line.at(0) == 'f')
        ReadPolygon(line, polygons_counter_, vertices_counter_);
    }
    SetExtrema();
  }
}

void Model::ClearData() {
  if (vertices_ != nullptr) delete[] vertices_;
  if (polygons_ != nullptr) {
    for (size_t i = 0; i < number_of_polygons_; ++i)
      delete[] polygons_[i].polygon_vertices_;
    delete[] polygons_;
  }
}

void Model::CountVertices(const std::string& line) {
  size_t pos = 0;
  while (true) {
    size_t x_start = line.find_first_of("-0123456789.", pos);
    if (x_start == std::string::npos) break;
    size_t x_end = line.find_first_not_of("-0123456789.eE", x_start);
    pos = line.find_first_of(' ', x_end);
    ++number_of_vertices_;
  }
}

void Model::CenterAndNormalize() {
  double total_x = 0;
  double total_y = 0;
  double total_z = 0;
  for (unsigned int i = 0; i < number_of_vertices_; i += 3) {
    total_x += vertices_[i];
    total_y += vertices_[i + 1];
    total_z += vertices_[i + 2];
  }
  Shift(-total_x / (number_of_vertices_ / 3) / kRatio, 0);
  Shift(-total_y / (number_of_vertices_ / 3) / kRatio, 1);
  Shift(-total_z / (number_of_vertices_ / 3) / kRatio - 0.5, 2);
  double scale_value =
      (std::max(std::max(extrema_[1] - extrema_[0], extrema_[3] - extrema_[2]),
                extrema_[5] - extrema_[4]));
  scale_value = 2.5 / scale_value;
  for (size_t i = 0; i < number_of_vertices_; ++i) vertices_[i] *= scale_value;
}

void Model::ReadVertices(const std::string& line, unsigned int& counter) {
  size_t pos = 0;
  while (true) {
    size_t x_start = line.find_first_of("-0123456789.", pos);
    if (x_start == std::string::npos) break;
    size_t x_end = line.find_first_not_of("-0123456789.eE", x_start);
    double x = std::stod(line.substr(x_start, x_end));
    vertices_[counter++] = std::move(x);
    pos = line.find_first_of(' ', x_end);
  }
}

void Model::SetExtrema() {
  extrema_[0] = vertices_[0];
  extrema_[1] = vertices_[0];
  extrema_[2] = vertices_[1];
  extrema_[3] = vertices_[1];
  extrema_[4] = vertices_[2];
  extrema_[5] = vertices_[2];
  for (size_t i = 3; i < number_of_vertices_; i += 3) {
    if (vertices_[i] < extrema_[0]) extrema_[0] = vertices_[i];
    if (vertices_[i] > extrema_[1]) extrema_[1] = vertices_[i];
    if (vertices_[i + 1] < extrema_[2]) extrema_[2] = vertices_[i + 1];
    if (vertices_[i + 1] > extrema_[3]) extrema_[3] = vertices_[i + 1];
    if (vertices_[i + 2] < extrema_[4]) extrema_[4] = vertices_[i + 2];
    if (vertices_[i + 2] > extrema_[5]) extrema_[5] = vertices_[i + 2];
  }
}

void Model::ReadPolygon(const std::string& line, unsigned int& counter,
                        const unsigned int& vertices_counter) {
  size_t pos = 0;
  unsigned int polygon_size = 0;
  while (true) {
    size_t vertex_start = line.find_first_of("-0123456789", pos);
    if (vertex_start == std::string::npos) break;
    size_t vertex_end = line.find_first_not_of("-0123456789", vertex_start);
    pos = line.find_first_of(' ', vertex_end);
    ++polygon_size;
  }
  if (polygon_size < 3) {
    number_of_polygons_ = 0;
    throw std::out_of_range("File contains invalid polygon");
  }
  polygons_[counter].polygon_size_ =
      polygon_size * 2;  // opengl требует зацикленные полигоны на вход, вместо
                         // {1, 2, 3} должен быть {1, 2, 2, 3, 3, 1}
  polygons_[counter].polygon_vertices_ = new unsigned int[polygon_size * 2];

  unsigned int index = 0;
  pos = 0;
  while (true) {
    size_t vertex_start = line.find_first_of("-0123456789", pos);
    if (vertex_start == std::string::npos) break;
    size_t vertex_end = line.find_first_not_of("-0123456789", vertex_start);
    int vertex_index = std::stoi(line.substr(vertex_start, vertex_end)) - 1;
    if (vertex_index < 0)
      vertex_index = vertices_counter / 3 + 1 + vertex_index;
    pos = line.find_first_of(' ', vertex_end);
    polygons_[counter].polygon_vertices_[index++] = vertex_index;
    if (index == 1) continue;
    polygons_[counter].polygon_vertices_[index++] = vertex_index;
  }

  polygons_[counter].polygon_vertices_[polygon_size * 2 - 1] =
      polygons_[counter].polygon_vertices_[0];
  ++counter;
}

void Model::Shift(double shift, int axis) {
  for (size_t i = axis; i < number_of_vertices_; i += 3) {
    vertices_[i] += kRatio * shift;
  }
}

void Model::Scale(double value) {
  if (value > 0)
    value = (1 + value / 100);
  else if (value < 0)
    value = (100 / (100 - value));
  for (size_t i = 0; i < number_of_vertices_; ++i) {
    vertices_[i] *= value;
  }
}

void Model::Rotate(double angle, int axis) {
  switch (axis) {
    case 0:
      RotateOx(kRatio * angle);
      break;
    case 1:
      RotateOy(kRatio * angle);
      break;
    case 2:
      RotateOz(kRatio * angle);
      break;
  }
}

void Model::RotateOx(double angle) {
  for (size_t i = 0; i < number_of_vertices_; i += 3) {
    double current_y = vertices_[i + 1];
    double current_z = vertices_[i + 2];
    vertices_[i + 1] = cos(angle) * current_y - sin(angle) * current_z;
    vertices_[i + 2] = sin(angle) * current_y + cos(angle) * current_z;
  }
}

void Model::RotateOy(double angle) {
  for (size_t i = 0; i < number_of_vertices_; i += 3) {
    double current_x = vertices_[i];
    double current_z = vertices_[i + 2];
    vertices_[i] = cos(angle) * current_x - sin(angle) * current_z;
    vertices_[i + 2] = sin(angle) * current_x + cos(angle) * current_z;
  }
}

void Model::RotateOz(double angle) {
  for (size_t i = 0; i < number_of_vertices_; i += 3) {
    double current_x = vertices_[i];
    double current_y = vertices_[i + 1];
    vertices_[i] = cos(angle) * current_x - sin(angle) * current_y;
    vertices_[i + 1] = sin(angle) * current_x + cos(angle) * current_y;
  }
}

}  // namespace s21
