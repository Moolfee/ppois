#include "domain/resort/MealPlan/MealPlan.h"
#include "domain/resort/ResortRoom/ResortRoom.h"
#include <gtest/gtest.h>

TEST(ResortRoom, ConfiguresAndDescribes) {
  ResortRoom item;
  auto partner = std::make_shared<MealPlan>();
  item.configureResortRoom(partner, 2);
  EXPECT_TRUE(!item.describeResortRoom().empty());
}
