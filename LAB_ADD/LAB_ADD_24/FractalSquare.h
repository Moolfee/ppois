#pragma once

#include <vector>

class FractalSquare {
public:
  struct Square {
    double centerX = 0.0;
    double centerY = 0.0;
    double side = 0.0;
    double angleRad = 0.0;
  };

  static std::vector<Square> generate(int depth, double side);
};
