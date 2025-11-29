#include "domain/visitors/MembershipProgram/MembershipProgram.h"
#include <gtest/gtest.h>

TEST(MembershipProgram, EnrollsVisitor) {
  MembershipProgram program;
  VisitorProfile visitorProfile;
  visitorProfile.logGuideInteraction("Intro");
  program.enrollVisitor(visitorProfile);
  EXPECT_GT(program.membershipSnapshot().size(), 0U);
}
