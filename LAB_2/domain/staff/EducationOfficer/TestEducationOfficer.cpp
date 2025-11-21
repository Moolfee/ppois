#include <gtest/gtest.h>
#include "domain/staff/EducationOfficer/EducationOfficer.h"

TEST(EducationOfficer, TailorsLesson) {
    EducationOfficer officer;
    VisitorProfile visitorProfile;
    officer.tailorLesson(visitorProfile);
    EXPECT_NE(officer.educationSnapshot().find("count"), std::string::npos);
}