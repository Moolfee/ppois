#include "domain/BogoSorter/BogoSorter.h"
#include <gtest/gtest.h>
#include <vector>

TEST(BogoSorter, SortsSmallIntegerVector) {
  std::vector<int> values = {3, 1, 2};
  BogoSorter::sortVector(values);
  EXPECT_EQ(values.size(), 3u);
  EXPECT_EQ(values[0], 1);
  EXPECT_EQ(values[1], 2);
  EXPECT_EQ(values[2], 3);
}

TEST(BogoSorter, LeavesSortedVectorIntact) {
  std::vector<int> values = {1, 2, 3};
  BogoSorter::sortVector(values);
  EXPECT_EQ(values[0], 1);
  EXPECT_EQ(values[1], 2);
  EXPECT_EQ(values[2], 3);
}
