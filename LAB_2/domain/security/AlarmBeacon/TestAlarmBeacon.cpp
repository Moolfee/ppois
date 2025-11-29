#include "domain/security/AlarmBeacon/AlarmBeacon.h"
#include <gtest/gtest.h>

TEST(AlarmBeacon, BroadcastsAlert) {
  AlarmBeacon beacon;
  VisitorProfile visitorProfile;
  EmergencyExitControl exitControl;
  exitControl.guideVisitor(visitorProfile);
  beacon.broadcastAlert(exitControl);
  EXPECT_NE(beacon.beaconSignature().find("vol"), std::string::npos);
}
