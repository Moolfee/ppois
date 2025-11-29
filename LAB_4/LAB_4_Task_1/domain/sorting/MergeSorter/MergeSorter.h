#pragma once

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

template <typename T> class MergeSorter {
public:
  static std::vector<T> sort(const std::vector<T> &source);

private:
  static void splitAndMerge(std::vector<T> &working, std::vector<T> &buffer,
                            std::size_t leftIndex, std::size_t rightIndex);

  static void performMerge(std::vector<T> &working, std::vector<T> &buffer,
                           std::size_t leftIndex, std::size_t midIndex,
                           std::size_t rightIndex);
};

template <typename T>
std::vector<T> MergeSorter<T>::sort(const std::vector<T> &source) {
  if (source.size() <= 1) {
    return source;
  }
  std::vector<T> working = source;
  std::vector<T> buffer(source.size());

  splitAndMerge(working, buffer, 0, working.size());
  return working;
}

template <typename T>
void MergeSorter<T>::splitAndMerge(std::vector<T> &working,
                                   std::vector<T> &buffer,
                                   std::size_t leftIndex,
                                   std::size_t rightIndex) {
  const std::size_t length = rightIndex - leftIndex;
  if (length <= 1) {
    return;
  }
  const std::size_t midIndex = leftIndex + length / 2;
  splitAndMerge(working, buffer, leftIndex, midIndex);
  splitAndMerge(working, buffer, midIndex, rightIndex);
  performMerge(working, buffer, leftIndex, midIndex, rightIndex);
}

template <typename T>
void MergeSorter<T>::performMerge(std::vector<T> &working,
                                  std::vector<T> &buffer, std::size_t leftIndex,
                                  std::size_t midIndex,
                                  std::size_t rightIndex) {
  std::size_t leftCursor = leftIndex;
  std::size_t rightCursor = midIndex;
  std::size_t bufferCursor = leftIndex;

  while (leftCursor < midIndex && rightCursor < rightIndex) {
    if (working[leftCursor] <= working[rightCursor]) {
      buffer[bufferCursor] = working[leftCursor];
      leftCursor++;
    } else {
      buffer[bufferCursor] = working[rightCursor];
      rightCursor++;
    }
    bufferCursor++;
  }
  const std::size_t leftTail = midIndex - leftCursor;
  const std::size_t rightTail = rightIndex - rightCursor;
  if (leftTail > 0) {
    std::copy_n(working.begin() + static_cast<std::ptrdiff_t>(leftCursor),
                static_cast<std::ptrdiff_t>(leftTail),
                buffer.begin() + static_cast<std::ptrdiff_t>(bufferCursor));
    bufferCursor += leftTail;
  }
  if (rightTail > 0) {
    std::copy_n(working.begin() + static_cast<std::ptrdiff_t>(rightCursor),
                static_cast<std::ptrdiff_t>(rightTail),
                buffer.begin() + static_cast<std::ptrdiff_t>(bufferCursor));
  }

  std::copy(buffer.begin() + static_cast<std::ptrdiff_t>(leftIndex),
            buffer.begin() + static_cast<std::ptrdiff_t>(rightIndex),
            working.begin() + static_cast<std::ptrdiff_t>(leftIndex));
}
