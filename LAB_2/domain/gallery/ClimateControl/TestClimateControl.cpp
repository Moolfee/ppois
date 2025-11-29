#include "domain/gallery/ClimateControl/ClimateControl.h"
#include <gtest/gtest.h>

TEST(ClimateControl, HandlesStableAndSpikeScenarios) {
  ClimateControl control;

  control.stabilizeAir(30);
  EXPECT_EQ(control.compileStatus().find("Cooling") == std::string::npos, true);

  bool alertTriggered = false;
  try {
    control.stabilizeAir(250);
  } catch (const ClimateAlertException &) {
    alertTriggered = true;
  }
  EXPECT_TRUE(alertTriggered);
}
