#include "domain/partners/PartnerHotel/PartnerHotel.h"
#include "domain/resort/MealPlan/MealPlan.h"
#include <gtest/gtest.h>

TEST(MealPlan, ConfiguresAndDescribes) {
  MealPlan item;
  auto partner = std::make_shared<PartnerHotel>();
  item.configureMealPlan(partner, 2);
  EXPECT_TRUE(!item.describeMealPlan().empty());
}
