#pragma once

#include <cstddef>
#include <vector>

class BogoSorter {
public:
  static void sortVector(std::vector<int> &items);

private:
  static std::size_t calculateAttemptLimit(std::size_t elementCount);

  static bool isSorted(const int *rangeStart, const int *rangeEnd);
  static void shuffleRange(int *rangeStart, int *rangeEnd);
};
