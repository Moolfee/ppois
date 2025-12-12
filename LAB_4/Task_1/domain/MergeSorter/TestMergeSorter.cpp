#include "domain/MergeSorter/MergeSorter.h"
#include <gtest/gtest.h>
#include <vector>

TEST(MergeSorter, SortsIntegerVector) {
  std::vector<int> values = {5, 1, 3, 2, 4};
  MergeSorter::sortVector(values);
  EXPECT_EQ(values.size(), 5u);
  EXPECT_EQ(values[0], 1);
  EXPECT_EQ(values[1], 2);
  EXPECT_EQ(values[2], 3);
  EXPECT_EQ(values[3], 4);
  EXPECT_EQ(values[4], 5);
}

TEST(MergeSorter, HandlesAlreadySortedVector) {
  std::vector<int> values = {1, 2, 3, 4};
  MergeSorter::sortVector(values);
  EXPECT_EQ(values[0], 1);
  EXPECT_EQ(values[1], 2);
  EXPECT_EQ(values[2], 3);
  EXPECT_EQ(values[3], 4);
}
