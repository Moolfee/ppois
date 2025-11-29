#include "domain/operations/TravelPolicy/TravelPolicy.h"
#include "domain/staff/ComplianceOfficer/ComplianceOfficer.h"
#include <gtest/gtest.h>

TEST(ComplianceOfficer, ConfiguresAndDescribes) {
  ComplianceOfficer item;
  auto partner = std::make_shared<TravelPolicy>();
  item.configureComplianceOfficer(partner, 2);
  EXPECT_TRUE(!item.describeComplianceOfficer().empty());
}
