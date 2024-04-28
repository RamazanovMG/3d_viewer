// Copyright [2023] <Phylis Crystobal, Morris Roggo>
#include "unit_tests.h"

#include <cmath>
#include <string>

TEST(GeneralSuite, test_1) {
  s21::Controller controller(&s21::Model::GetInstance());
  controller.OpenFile("../data-samples/cube.pepega");
  ASSERT_EQ(*controller.GetVertices(), -1.25);
  ASSERT_EQ(controller.GetPolygons()->polygon_size_, 6);
  controller.Rotate(1, 0);
  controller.Rotate(1, 1);
  controller.Rotate(1, 2);
  controller.Shift(1, 0);
  controller.Shift(1, 1);
  controller.Shift(1, 2);
  controller.Scale(1);
  ASSERT_EQ(controller.GetNumberOfVertices(), 24);
  ASSERT_EQ(controller.GetNumberOfPolygons(), 10);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
