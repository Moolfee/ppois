#include "AStar.h"

#include <iostream>

namespace {
void printGridWithPath(const AStar::Grid &grid, const AStar::Path &path) {
  AStar::Grid copy = grid;
  for (const auto &p : path) {
    if (copy[p.row][p.col] == '.') {
      copy[p.row][p.col] = '*';
    }
  }

  for (const auto &row : copy) {
    std::cout << row << '\n';
  }
}
}

int main() {
  AStar::Grid grid = {"........", "..####..", "..#.....", "..#.###.",
                      "..#...#.", "..###.#.", "......#.", "........"};

  AStar::Point start{0, 0};
  AStar::Point goal{7, 7};

  auto path = AStar::findPath(grid, start, goal);
  if (path.empty()) {
    std::cout << "Path not found\n";
    return 0;
  }

  std::cout << "Path length: " << path.size() - 1 << "\n\n";
  printGridWithPath(grid, path);
  return 0;
}
