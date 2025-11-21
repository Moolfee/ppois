#include <gtest/gtest.h>
#include "domain/resort/ResortRoom/ResortRoom.h"
#include "domain/resort/MealPlan/MealPlan.h"

TEST(ResortRoom, ConfiguresAndDescribes) {
    ResortRoom item;
    auto partner = std::make_shared<MealPlan>();
    item.configureResortRoom(partner, 2);
    EXPECT_TRUE(!item.describeResortRoom().empty());
}