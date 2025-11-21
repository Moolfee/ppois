#include <gtest/gtest.h>
#include "domain/transport/AirportTransfer/AirportTransfer.h"
#include "domain/transport/FlightTicket/FlightTicket.h"

TEST(AirportTransfer, ConfiguresAndDescribes) {
    AirportTransfer item;
    auto partner = std::make_shared<FlightTicket>();
    item.configureAirportTransfer(partner, 2);
    EXPECT_TRUE(!item.describeAirportTransfer().empty());
}