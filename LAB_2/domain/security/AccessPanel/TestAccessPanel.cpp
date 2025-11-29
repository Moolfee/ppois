#include "domain/security/AccessPanel/AccessPanel.h"
#include <gtest/gtest.h>

TEST(AccessPanel, AuthorizesStaff) {
  AccessPanel panel;
  StaffMember member;
  member.assignRole("EveningGuard");
  panel.authorizeStaff(member);
  EXPECT_NE(panel.auditLabel().find("Gallery"), std::string::npos);

  StaffMember visitor;
  visitor.assignRole("Visitor");
  bool unauthorizedRaised = false;
  try {
    panel.authorizeStaff(visitor);
  } catch (const UnauthorizedAccessException &) {
    unauthorizedRaised = true;
  }
  EXPECT_TRUE(unauthorizedRaised);
}
