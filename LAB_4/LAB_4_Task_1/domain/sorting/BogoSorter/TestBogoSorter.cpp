#include "domain/sorting/BogoSorter/BogoSorter.h"
#include <gtest/gtest.h>
#include <ostream>

template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &values) {
  stream << "[";
  for (std::size_t index = 0; index < values.size(); index++) {
    stream << values[index];
    if (index + 1 < values.size()) {
      stream << ", ";
    }
  }
  stream << "]";
  return stream;
}

template <typename T>
void expectEqualVectors(const std::vector<T> &actual,
                        const std::vector<T> &expected) {
  EXPECT_EQ(actual.size(), expected.size());
  for (std::size_t index = 0; index < actual.size(); index++) {
    EXPECT_EQ(actual[index], expected[index]);
  }
}

static bool isSortedAscending(const std::vector<int> &values) {
  for (std::size_t index = 1; index < values.size(); index++) {
    if (values[index - 1] > values[index]) {
      return false;
    }
  }
  return true;
}

TEST(BogoSorter, SortsSmallVector) {
  std::vector<int> numbers = {3, 1, 2};
  auto sortedNumbers = BogoSorter<int>::sortRandomly(numbers, 5000);
  EXPECT_TRUE(isSortedAscending(sortedNumbers));
}

TEST(BogoSorter, StopsImmediatelyWhenSorted) {
  std::vector<int> numbers = {1, 2, 3};
  auto sortedNumbers = BogoSorter<int>::sortRandomly(numbers, 10);
  expectEqualVectors(numbers, sortedNumbers);
}

TEST(BogoSorter, HandlesEmptyVector) {
  std::vector<int> emptyValues;
  auto sortedNumbers = BogoSorter<int>::sortRandomly(emptyValues, 10);
  expectEqualVectors(emptyValues, sortedNumbers);
}

TEST(BogoSorter, RespectsZeroAttemptLimit) {
  std::vector<int> numbers = {2, 1};
  auto sortedNumbers = BogoSorter<int>::sortRandomly(numbers, 0);
  EXPECT_EQ(numbers.size(), sortedNumbers.size());
}

TEST(BogoSorter, KeepsSourceUntouched) {
  std::vector<int> numbers = {4, 2, 3};
  auto sortedNumbers = BogoSorter<int>::sortRandomly(numbers, 5000);
  expectEqualVectors(numbers, std::vector<int>{4, 2, 3});
  EXPECT_TRUE(isSortedAscending(sortedNumbers));
}

TEST(BogoSorter, SortsStringsWithLimitedAttempts) {
  std::vector<std::string> words = {"b", "a", "c"};
  auto sortedWords = BogoSorter<std::string>::sortRandomly(words, 8000);
  expectEqualVectors(sortedWords, std::vector<std::string>{"a", "b", "c"});
}
