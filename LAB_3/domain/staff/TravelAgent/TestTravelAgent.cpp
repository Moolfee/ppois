#include "domain/staff/TravelAgent/TravelAgent.h"
#include "domain/travelers/TouristProfile/TouristProfile.h"
#include <gtest/gtest.h>

TEST(TravelAgent, ConfiguresAndDescribes) {
  TravelAgent item;
  auto partner = std::make_shared<TouristProfile>();
  item.configureTravelAgent(partner, 2);
  EXPECT_TRUE(!item.describeTravelAgent().empty());
}
