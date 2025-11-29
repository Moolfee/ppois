#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"
#include "domain/staff/EmployeeProfile/EmployeeProfile.h"
#include <gtest/gtest.h>

TEST(EmployeeProfile, ConfiguresAndDescribes) {
  EmployeeProfile item;
  auto partner = std::make_shared<TravelAgencyProfile>();
  item.configureEmployeeProfile(partner, 2);
  EXPECT_TRUE(!item.describeEmployeeProfile().empty());
}
