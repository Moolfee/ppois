#include "domain/visitors/VisitorProfile/VisitorProfile.h"
#include <gtest/gtest.h>
#include <string>

TEST(VisitorProfile, LogsInteractionAndGuardsLimits) {
  VisitorProfile visitorProfile;
  visitorProfile.logGuideInteraction("Docent");
  EXPECT_NE(visitorProfile.compileOverview().find("Docent"), std::string::npos);

  bool exceptionRaised = false;
  try {
    for (int index = 0; index < 7; ++index) {
      visitorProfile.logGuideInteraction("Guide" + std::to_string(index));
    }
  } catch (const VisitorLimitExceededException &) {
    exceptionRaised = true;
  }
  EXPECT_TRUE(exceptionRaised);
}
