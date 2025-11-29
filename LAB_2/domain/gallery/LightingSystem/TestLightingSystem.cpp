#include "domain/gallery/LightingSystem/LightingSystem.h"
#include <gtest/gtest.h>

TEST(LightingSystem, AdjustsSceneDynamics) {
  LightingSystem lightingSystem;
  lightingSystem.adjustSceneDynamics(80);
  EXPECT_NE(lightingSystem.sceneLabel().find("Highlight"), std::string::npos);
}

TEST(LightingSystem, ClampsLuxBoundaries) {
  LightingSystem lightingSystem;
  lightingSystem.adjustSceneDynamics(-40);
  EXPECT_NE(lightingSystem.sceneLabel().find("-0"), std::string::npos);
  lightingSystem.adjustSceneDynamics(200);
  EXPECT_NE(lightingSystem.sceneLabel().find("-100"), std::string::npos);
}
