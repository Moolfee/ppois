#include "domain/staff/TravelAgent/TravelAgent.h"
#include "domain/travelers/FamilyBooking/FamilyBooking.h"
#include <gtest/gtest.h>

TEST(FamilyBooking, ConfiguresAndDescribes) {
  FamilyBooking item;
  auto partner = std::make_shared<TravelAgent>();
  item.configureFamilyBooking(partner, 2);
  EXPECT_TRUE(!item.describeFamilyBooking().empty());
}

TEST(FamilyBooking, AddsTravelersAndChecksEscortNeed) {
  FamilyBooking booking;
  booking.addTraveler(5);
  EXPECT_TRUE(booking.requiresEscort());
}
