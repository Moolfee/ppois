#include <gtest/gtest.h>
#include "domain/staff/HotelManager/HotelManager.h"
#include "domain/partners/PartnerHotel/PartnerHotel.h"

TEST(HotelManager, ConfiguresAndDescribes) {
    HotelManager item;
    auto partner = std::make_shared<PartnerHotel>();
    item.configureHotelManager(partner, 2);
    EXPECT_TRUE(!item.describeHotelManager().empty());
}