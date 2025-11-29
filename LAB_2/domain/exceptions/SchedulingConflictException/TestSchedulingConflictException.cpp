#include "domain/exceptions/SchedulingConflictException/SchedulingConflictException.h"
#include <gtest/gtest.h>

TEST(SchedulingConflictException, DescribesSchedulingIssue) {
  SchedulingConflictException exceptionInstance("Auditorium", 5, true);
  EXPECT_NE(exceptionInstance.describeIssue().find("Auditorium"),
            std::string::npos);
  SchedulingConflictException holdInstance("Gallery", 1, false);
  EXPECT_NE(holdInstance.scheduleMarker().find("hold"), std::string::npos);
}
