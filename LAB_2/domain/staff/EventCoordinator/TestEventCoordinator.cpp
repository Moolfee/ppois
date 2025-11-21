#include <gtest/gtest.h>
#include "domain/staff/EventCoordinator/EventCoordinator.h"

TEST(EventCoordinator, AlignsEducation) {
    EventCoordinator coordinator;
    EducationOfficer officer;
    coordinator.alignEducation(officer);
    EXPECT_NE(coordinator.eventSummary().find("Coord"), std::string::npos);
}