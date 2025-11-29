#include "domain/excursions/CruisePackage/CruisePackage.h"
#include "domain/resort/MealPlan/MealPlan.h"
#include <gtest/gtest.h>

TEST(CruisePackage, ConfiguresAndDescribes) {
  CruisePackage item;
  auto partner = std::make_shared<MealPlan>();
  item.configureCruisePackage(partner, 2);
  EXPECT_TRUE(!item.describeCruisePackage().empty());
}
