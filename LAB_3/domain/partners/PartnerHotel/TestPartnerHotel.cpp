#include <gtest/gtest.h>
#include "domain/partners/PartnerHotel/PartnerHotel.h"
#include "domain/resort/ResortProfile/ResortProfile.h"

TEST(PartnerHotel, ConfiguresAndDescribes) {
    PartnerHotel item;
    auto partner = std::make_shared<ResortProfile>();
    item.configurePartnerHotel(partner, 2);
    EXPECT_TRUE(!item.describePartnerHotel().empty());
}