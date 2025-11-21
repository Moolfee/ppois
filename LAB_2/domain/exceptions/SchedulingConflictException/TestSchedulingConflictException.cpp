#include <gtest/gtest.h>
#include "domain/exceptions/SchedulingConflictException/SchedulingConflictException.h"

TEST(SchedulingConflictException, DescribesSchedulingIssue) {
    SchedulingConflictException exceptionInstance("Auditorium", 5, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("Auditorium"), std::string::npos);
    SchedulingConflictException holdInstance("Gallery", 1, false);
    EXPECT_NE(holdInstance.scheduleMarker().find("hold"), std::string::npos);
}