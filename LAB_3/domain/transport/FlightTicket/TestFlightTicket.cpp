#include <gtest/gtest.h>
#include "domain/transport/FlightTicket/FlightTicket.h"
#include "domain/staff/TravelAgent/TravelAgent.h"

TEST(FlightTicket, ConfiguresAndDescribes) {
    FlightTicket item;
    auto partner = std::make_shared<TravelAgent>();
    item.configureFlightTicket(partner, 2);
    EXPECT_TRUE(!item.describeFlightTicket().empty());
}