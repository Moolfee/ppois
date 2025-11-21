#include <gtest/gtest.h>
#include "domain/travelers/FamilyBooking/FamilyBooking.h"
#include "domain/staff/TravelAgent/TravelAgent.h"

TEST(FamilyBooking, ConfiguresAndDescribes) {
    FamilyBooking item;
    auto partner = std::make_shared<TravelAgent>();
    item.configureFamilyBooking(partner, 2);
    EXPECT_TRUE(!item.describeFamilyBooking().empty());
}