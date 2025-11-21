#include <gtest/gtest.h>
#include "domain/security/CameraNetwork/CameraNetwork.h"

TEST(CameraNetwork, RecalibratesAngles) {
    CameraNetwork network;
    network.recalibrateAngles(1);
    EXPECT_NE(network.describeCoverage().find("HD"), std::string::npos);
    network.recalibrateAngles(4);
    EXPECT_NE(network.describeCoverage().find("SD"), std::string::npos);
}