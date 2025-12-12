#include "domain/BogoSorter/BogoSorter.h"

#include <cstdlib>
#include <ctime>

std::size_t BogoSorter::calculateAttemptLimit(std::size_t elementCount) {
  const std::size_t normalizedCount = elementCount == 0 ? 1 : elementCount;  
  return normalizedCount * normalizedCount * normalizedCount * 20 + 20;
}

bool BogoSorter::isSorted(const int *rangeStart, const int *rangeEnd) {
  for (const int *current = rangeStart; current + 1 < rangeEnd; ++current) {
    if (*(current + 1) < *current) {
      return false;
    }
  }
  return true;
}

void BogoSorter::shuffleRange(int *rangeStart, int *rangeEnd) {
  const std::size_t elementCount = static_cast<std::size_t>(rangeEnd - rangeStart);
  if (elementCount < 2) {
    return;
  }
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    seeded = true;
  }
  for (std::size_t index = elementCount - 1; index > 0; --index) {
    const std::size_t swapIndex =
        static_cast<std::size_t>(std::rand()) % (index + 1);

    int *first = rangeStart + static_cast<std::ptrdiff_t>(index);    
    int *second = rangeStart + static_cast<std::ptrdiff_t>(swapIndex);

    const int movedValue = *first;
    *first = *second;
    *second = movedValue;
  }
}

void BogoSorter::sortVector(std::vector<int> &items) {  
  if (items.size() < 2) {
    return;
  }

  const std::size_t maxAttempts = calculateAttemptLimit(items.size());
  std::size_t attemptCount = 0;
  while (!isSorted(items.data(),
                   items.data() + static_cast<std::ptrdiff_t>(items.size())) &&
         attemptCount < maxAttempts) {
    
    shuffleRange(items.data(), items.data() + static_cast<std::ptrdiff_t>(items.size()));
    attemptCount ++;
  }
}
