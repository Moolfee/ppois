#include "AStar.h"

#include <algorithm>
#include <cmath>
#include <stdexcept>

AStar::Path AStar::findPath(const Grid &grid, Point start, Point goal) {
  if (!inBounds(grid, start) || !inBounds(grid, goal)) {
    throw std::out_of_range("Start or goal is outside of the grid");
  }
  if (!passable(grid, start) || !passable(grid, goal)) {
    throw std::invalid_argument("Start or goal is blocked");
  }

  std::priority_queue<ScoredPoint> openSet;
  std::unordered_map<Point, double, PointHash> gScore;
  std::unordered_map<Point, Point, PointHash> cameFrom;

  gScore[start] = 0.0;
  std::size_t pushOrder = 0;
  openSet.push({heuristic(start, goal), pushOrder++, start});

  const Point directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!openSet.empty()) {
    const Point current = openSet.top().point;
    openSet.pop();

    if (current == goal) {
      Path path;
      Point cursor = goal;
      while (!(cursor == start)) {
        path.push_back(cursor);
        cursor = cameFrom[cursor];
      }
      path.push_back(start);
      std::reverse(path.begin(), path.end());
      return path;
    }

    for (const auto &dir : directions) {
      Point neighbor{current.row + dir.row, current.col + dir.col};
      if (!inBounds(grid, neighbor) || !passable(grid, neighbor)) {
        continue;
      }

      const double tentativeScore = gScore[current] + 1.0;
      auto it = gScore.find(neighbor);
      if (it == gScore.end() || tentativeScore < it->second) {
        gScore[neighbor] = tentativeScore;
        cameFrom[neighbor] = current;
        const double fScore = tentativeScore + heuristic(neighbor, goal);
        openSet.push({fScore, pushOrder++, neighbor});
      }
    }
  }

  return {};
}

bool AStar::inBounds(const Grid &grid, const Point &p) {
  return p.row >= 0 && p.col >= 0 && static_cast<std::size_t>(p.row) < grid.size() &&
         static_cast<std::size_t>(p.col) < grid[p.row].size();
}

bool AStar::passable(const Grid &grid, const Point &p) {
  return grid[p.row][p.col] != '#';
}

double AStar::heuristic(const Point &a, const Point &b) {
  return static_cast<double>(std::abs(a.row - b.row) +
                             std::abs(a.col - b.col));
}
