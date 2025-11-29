#include "domain/partners/PartnerAirline/PartnerAirline.h"
#include "domain/staff/AirlineManager/AirlineManager.h"
#include <gtest/gtest.h>

TEST(AirlineManager, ConfiguresAndDescribes) {
  AirlineManager item;
  auto partner = std::make_shared<PartnerAirline>();
  item.configureAirlineManager(partner, 2);
  EXPECT_TRUE(!item.describeAirlineManager().empty());
}
