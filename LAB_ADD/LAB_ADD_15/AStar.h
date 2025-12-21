#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class AStar {
public:
  struct Point {
    int row = 0;
    int col = 0;
    bool operator==(const Point &other) const {
      return row == other.row && col == other.col;
    }
  };

  using Grid = std::vector<std::string>;
  using Path = std::vector<Point>;

  static Path findPath(const Grid &grid, Point start, Point goal);

private:
  struct PointHash {
    std::size_t operator()(const Point &p) const noexcept {
      return static_cast<std::size_t>(p.row) * 73856093u +
             static_cast<std::size_t>(p.col) * 19349663u;
    }
  };

  struct ScoredPoint {
    double fScore = 0.0;
    std::size_t order = 0;
    Point point;
    bool operator<(const ScoredPoint &other) const {
      if (fScore == other.fScore) {
        return order > other.order;
      }
      return fScore > other.fScore;
    }
  };

  static bool inBounds(const Grid &grid, const Point &p);
  static bool passable(const Grid &grid, const Point &p);
  static double heuristic(const Point &a, const Point &b);
};
