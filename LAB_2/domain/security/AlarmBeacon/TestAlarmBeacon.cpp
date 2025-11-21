#include <gtest/gtest.h>
#include "domain/security/AlarmBeacon/AlarmBeacon.h"

TEST(AlarmBeacon, BroadcastsAlert) {
    AlarmBeacon beacon;
    VisitorProfile visitorProfile;
    EmergencyExitControl exitControl;
    exitControl.guideVisitor(visitorProfile);
    beacon.broadcastAlert(exitControl);
    EXPECT_NE(beacon.beaconSignature().find("vol"), std::string::npos);
}