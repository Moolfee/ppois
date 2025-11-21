#include <gtest/gtest.h>
#include "domain/operations/TravelPolicy/TravelPolicy.h"
#include "domain/staff/ComplianceOfficer/ComplianceOfficer.h"

TEST(TravelPolicy, ConfiguresAndDescribes) {
    TravelPolicy item;
    auto partner = std::make_shared<ComplianceOfficer>();
    item.configureTravelPolicy(partner, 2);
    EXPECT_TRUE(!item.describeTravelPolicy().empty());
}