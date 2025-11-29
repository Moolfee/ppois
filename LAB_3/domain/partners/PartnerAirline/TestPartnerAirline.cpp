#include "domain/partners/PartnerAirline/PartnerAirline.h"
#include "domain/transport/FlightTicket/FlightTicket.h"
#include <gtest/gtest.h>

TEST(PartnerAirline, ConfiguresAndDescribes) {
  PartnerAirline item;
  auto partner = std::make_shared<FlightTicket>();
  item.configurePartnerAirline(partner, 2);
  EXPECT_TRUE(!item.describePartnerAirline().empty());
}

TEST(PartnerAirline, PublishesScheduleAndAllianceFlag) {
  PartnerAirline airline;
  auto partner = std::make_shared<FlightTicket>();
  airline.configurePartnerAirline(partner, 1);
  airline.publishSchedule("summer");
  EXPECT_TRUE(airline.hasAlliance());
  EXPECT_NE(airline.describePartnerAirline().find("sched:summer"), std::string::npos);
}
