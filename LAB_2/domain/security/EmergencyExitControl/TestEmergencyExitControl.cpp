#include <gtest/gtest.h>
#include "domain/security/EmergencyExitControl/EmergencyExitControl.h"

TEST(EmergencyExitControl, GuidesNormalAndOverflowVisitors) {
    EmergencyExitControl control;
    VisitorProfile visitorProfile;
    control.guideVisitor(visitorProfile);
    EXPECT_NE(control.escapeBriefing().find("Signs"), std::string::npos);

    visitorProfile.logGuideInteraction("ExtremelyLongGuidedTourSectionForEmergencyFlow");
    bool exceptionRaised = false;
    try {
        control.guideVisitor(visitorProfile);
    } catch (const VisitorLimitExceededException&) {
        exceptionRaised = true;
    }
    EXPECT_TRUE(exceptionRaised);
}