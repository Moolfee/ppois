#include <gtest/gtest.h>
#include "domain/staff/StaffMember/StaffMember.h"

TEST(StaffMember, AssignsRole) {
    StaffMember staff;
    staff.assignRole("Guide");
    EXPECT_NE(staff.describeProfile().find("role"), std::string::npos);
}