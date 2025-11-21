#include <gtest/gtest.h>
#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"
#include "domain/operations/TravelPolicy/TravelPolicy.h"

TEST(TravelAgencyProfile, ConfiguresAndDescribes) {
    TravelAgencyProfile item;
    auto partner = std::make_shared<TravelPolicy>();
    item.configureTravelAgencyProfile(partner, 2);
    EXPECT_TRUE(!item.describeTravelAgencyProfile().empty());
}