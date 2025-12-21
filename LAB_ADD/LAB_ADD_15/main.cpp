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

void runCase(const std::string &title, const AStar::Grid &grid,
             AStar::Point start, AStar::Point goal) {
  std::cout << title << "\n";
  auto path = AStar::findPath(grid, start, goal);
  if (path.empty()) {
    std::cout << "Path not found\n\n";
    return;
  }
  std::cout << "Path length: " << path.size() - 1 << "\n\n";
  printGridWithPath(grid, path);
  std::cout << "\n";
}
}

int main() {
  runCase("Case 1",
          {"........", "..####..", "..#.....", "..#.###.", "..#...#.",
           "..###.#.", "......#.", "........"},
          {0, 0}, {7, 7});

  runCase("Case 2",
          {"............", "..####..####", "..#....#....", "..#....#....",
           "..#....#....", "..#....#....", "..#....#....", "..#....#....",
           "..#....#....", ".####..####.", "#..........."},
          {0, 0}, {10, 11});

  runCase("Case 3",
          {"...............#", ".#####.########..",
           ".#...#.......#...", ".#.#.#####.#.#...",
           ".#.#.....#.#...#", ".#.#.###.#.###...",
           ".#...#.#.#...#...", ".###.#.#.###.#...",
           ".#...#...#...#...", ".#.#.#####.#.###.",
           ".#.#.....#.....#.", ".#####.#####.##..",
           "#................"},
          {0, 0}, {12, 16});
  return 0;
}
