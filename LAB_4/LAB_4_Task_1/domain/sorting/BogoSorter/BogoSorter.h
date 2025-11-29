#pragma once

#include <algorithm>
#include <cstddef>
#include <random>
#include <string>
#include <vector>

template <typename T> class BogoSorter {
public:
  static std::vector<T> sortRandomly(const std::vector<T> &source,
                                     std::size_t maxAttempts = 50000);

private:
  static bool isOrdered(const std::vector<T> &candidate);
};

template <typename T>
std::vector<T> BogoSorter<T>::sortRandomly(const std::vector<T> &source,
                                           std::size_t maxAttempts) {
  if (source.size() <= 1) {
    return source;
  }
  std::vector<T> candidate = source;
  std::mt19937 generator(std::random_device{}());
  std::size_t attemptCount = 0;

  while (attemptCount < maxAttempts && !isOrdered(candidate)) {
    std::shuffle(candidate.begin(), candidate.end(), generator);
    attemptCount++;
  }
  return candidate;
}

template <typename T>
bool BogoSorter<T>::isOrdered(const std::vector<T> &candidate) {
  if (candidate.empty()) {
    return true;
  }
  for (std::size_t index = 1; index < candidate.size(); index++) {
    if (candidate[index - 1] > candidate[index]) {
      return false;
    }
  }
  return true;
}
