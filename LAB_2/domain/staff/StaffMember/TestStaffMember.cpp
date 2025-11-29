#include "domain/staff/StaffMember/StaffMember.h"
#include <gtest/gtest.h>

TEST(StaffMember, AssignsRole) {
  StaffMember staff;
  staff.assignRole("Guide");
  EXPECT_NE(staff.describeProfile().find("role"), std::string::npos);
}
