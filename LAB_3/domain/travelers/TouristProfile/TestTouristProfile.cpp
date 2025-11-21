#include <gtest/gtest.h>
#include "domain/travelers/TouristProfile/TouristProfile.h"
#include "domain/travelers/InsurancePlan/InsurancePlan.h"

TEST(TouristProfile, ConfiguresAndDescribes) {
    TouristProfile item;
    auto partner = std::make_shared<InsurancePlan>();
    item.configureTouristProfile(partner, 2);
    EXPECT_TRUE(!item.describeTouristProfile().empty());
}