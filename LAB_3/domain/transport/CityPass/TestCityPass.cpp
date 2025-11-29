#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/transport/CityPass/CityPass.h"
#include <gtest/gtest.h>

TEST(CityPass, ConfiguresAndDescribes) {
  CityPass item;
  auto partner = std::make_shared<ExcursionPlan>();
  item.configureCityPass(partner, 2);
  EXPECT_TRUE(!item.describeCityPass().empty());
}
