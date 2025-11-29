#include "domain/staff/EventCoordinator/EventCoordinator.h"
#include <gtest/gtest.h>

TEST(EventCoordinator, AlignsEducation) {
  EventCoordinator coordinator;
  EducationOfficer officer;
  coordinator.alignEducation(officer);
  EXPECT_NE(coordinator.eventSummary().find("Coord"), std::string::npos);
}
