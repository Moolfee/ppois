#include "domain/operations/TravelPolicy/TravelPolicy.h"
#include "domain/travelers/InsurancePlan/InsurancePlan.h"
#include <gtest/gtest.h>

TEST(InsurancePlan, ConfiguresAndDescribes) {
  InsurancePlan item;
  auto partner = std::make_shared<TravelPolicy>();
  item.configureInsurancePlan(partner, 2);
  EXPECT_TRUE(!item.describeInsurancePlan().empty());
}

TEST(InsurancePlan, AddsCoverageAndChecksEmergency) {
  InsurancePlan plan;
  plan.addCoverage("emergency");
  EXPECT_TRUE(plan.coversEmergency());
}
