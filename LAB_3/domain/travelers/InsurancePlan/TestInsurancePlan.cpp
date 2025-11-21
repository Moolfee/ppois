#include <gtest/gtest.h>
#include "domain/travelers/InsurancePlan/InsurancePlan.h"
#include "domain/operations/TravelPolicy/TravelPolicy.h"

TEST(InsurancePlan, ConfiguresAndDescribes) {
    InsurancePlan item;
    auto partner = std::make_shared<TravelPolicy>();
    item.configureInsurancePlan(partner, 2);
    EXPECT_TRUE(!item.describeInsurancePlan().empty());
}