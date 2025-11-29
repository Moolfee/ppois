#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/excursions/ScenicRoute/ScenicRoute.h"
#include <gtest/gtest.h>

TEST(ScenicRoute, ConfiguresAndDescribes) {
  ScenicRoute item;
  auto partner = std::make_shared<ExcursionPlan>();
  item.configureScenicRoute(partner, 2);
  EXPECT_TRUE(!item.describeScenicRoute().empty());
}
