#include "domain/staff/TravelAgent/TravelAgent.h"
#include "domain/transport/FlightTicket/FlightTicket.h"
#include <gtest/gtest.h>

TEST(FlightTicket, ConfiguresAndDescribes) {
  FlightTicket item;
  auto partner = std::make_shared<TravelAgent>();
  item.configureFlightTicket(partner, 2);
  EXPECT_TRUE(!item.describeFlightTicket().empty());
}

TEST(FlightTicket, UpgradesCabinAndBlocksSeat) {
  FlightTicket ticket;
  ticket.upgradeCabin("business");
  ticket.blockSeat();
  EXPECT_NE(ticket.describeFlightTicket().find("cabin"), std::string::npos);
}
