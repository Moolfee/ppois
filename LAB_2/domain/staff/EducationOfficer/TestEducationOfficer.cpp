#include "domain/staff/EducationOfficer/EducationOfficer.h"
#include <gtest/gtest.h>

TEST(EducationOfficer, TailorsLesson) {
  EducationOfficer officer;
  VisitorProfile visitorProfile;
  officer.tailorLesson(visitorProfile);
  EXPECT_NE(officer.educationSnapshot().find("count"), std::string::npos);
}
