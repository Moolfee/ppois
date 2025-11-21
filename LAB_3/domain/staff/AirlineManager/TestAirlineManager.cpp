#include <gtest/gtest.h>
#include "domain/staff/AirlineManager/AirlineManager.h"
#include "domain/partners/PartnerAirline/PartnerAirline.h"

TEST(AirlineManager, ConfiguresAndDescribes) {
    AirlineManager item;
    auto partner = std::make_shared<PartnerAirline>();
    item.configureAirlineManager(partner, 2);
    EXPECT_TRUE(!item.describeAirlineManager().empty());
}