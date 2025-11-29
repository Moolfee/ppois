#include "domain/operations/CleaningSchedule/CleaningSchedule.h"
#include <gtest/gtest.h>

TEST(CleaningSchedule, AssignsCaretaker) {
  CleaningSchedule schedule;
  schedule.assignCaretaker("Clara");
  EXPECT_NE(schedule.outlineSanitationPlan().find("Clara"), std::string::npos);
  schedule.assignCaretaker("Eve");
  schedule.assignCaretaker("Jim");
  EXPECT_NE(schedule.outlineSanitationPlan().find("overnight-true"),
            std::string::npos);
}
