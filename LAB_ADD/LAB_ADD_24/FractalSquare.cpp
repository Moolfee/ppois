#include "FractalSquare.h"

#include <cmath>
#include <vector>

namespace {
struct Vec {
  double x = 0.0;
  double y = 0.0;
  Vec operator+(const Vec &other) const { return {x + other.x, y + other.y}; }
  Vec operator-(const Vec &other) const { return {x - other.x, y - other.y}; }
  Vec operator*(double k) const { return {x * k, y * k}; }
};

Vec normalize(const Vec &v) {
  const double len = std::sqrt(v.x * v.x + v.y * v.y);
  return len == 0.0 ? Vec{0.0, 0.0} : Vec{v.x / len, v.y / len};
}

double angleOf(const Vec &v) { return std::atan2(v.y, v.x); }

Vec ensureNormalFacing(const Vec &candidate, const Vec &reference) {
  double dot = candidate.x * reference.x + candidate.y * reference.y;
  if (dot < 0.0) {
    return {-candidate.x, -candidate.y};
  }
  return candidate;
}

void generateByEdge(std::vector<FractalSquare::Square> &result, int depth,
                    const Vec &left, const Vec &right, const Vec &parentNormal) {
  Vec edge = right - left;
  const double side = std::sqrt(edge.x * edge.x + edge.y * edge.y);
  if (side == 0.0) {
    return;
  }

  Vec u = normalize(edge);
  Vec n = ensureNormalFacing(Vec{-u.y, u.x}, parentNormal);

  Vec baseMid{(left.x + right.x) / 2.0, (left.y + right.y) / 2.0};
  Vec center = baseMid + n * (side / 2.0);
  result.push_back({center.x, center.y, side, angleOf(u)});

  if (depth == 0) {
    return;
  }

  Vec topMid = center + n * (side / 2.0);
  Vec topLeft = topMid - u * (side / 2.0);
  Vec topRight = topMid + u * (side / 2.0);
  Vec apex = topMid + n * (side / 2.0);

  generateByEdge(result, depth - 1, topLeft, apex, n);
  generateByEdge(result, depth - 1, apex, topRight, n);
}
}

std::vector<FractalSquare::Square> FractalSquare::generate(int depth,
                                                           double side) {
  std::vector<Square> result;
  if (depth < 0 || side <= 0.0) {
    return result;
  }

  Vec left{0.0, 0.0};
  Vec right{side, 0.0};
  Vec normal{0.0, 1.0};
  generateByEdge(result, depth, left, right, normal);
  return result;
}
