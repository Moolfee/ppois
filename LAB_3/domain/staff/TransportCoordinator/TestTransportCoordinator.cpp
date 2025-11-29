#include "domain/staff/TransportCoordinator/TransportCoordinator.h"
#include "domain/transport/AirportTransfer/AirportTransfer.h"
#include <gtest/gtest.h>

TEST(TransportCoordinator, ConfiguresAndDescribes) {
  TransportCoordinator item;
  auto partner = std::make_shared<AirportTransfer>();
  item.configureTransportCoordinator(partner, 2);
  EXPECT_TRUE(!item.describeTransportCoordinator().empty());
}
