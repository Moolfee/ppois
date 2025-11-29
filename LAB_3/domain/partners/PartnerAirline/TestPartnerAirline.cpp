#include "domain/partners/PartnerAirline/PartnerAirline.h"
#include "domain/transport/FlightTicket/FlightTicket.h"
#include <gtest/gtest.h>

TEST(PartnerAirline, ConfiguresAndDescribes) {
  PartnerAirline item;
  auto partner = std::make_shared<FlightTicket>();
  item.configurePartnerAirline(partner, 2);
  EXPECT_TRUE(!item.describePartnerAirline().empty());
}
