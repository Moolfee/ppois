#include "domain/travelers/InsurancePlan/InsurancePlan.h"
#include "domain/travelers/TouristProfile/TouristProfile.h"
#include <gtest/gtest.h>

TEST(TouristProfile, ConfiguresAndDescribes) {
  TouristProfile item;
  auto partner = std::make_shared<InsurancePlan>();
  item.configureTouristProfile(partner, 2);
  EXPECT_TRUE(!item.describeTouristProfile().empty());
}
