#include "domain/gallery/LightingSystem/LightingSystem.h"

void LightingSystem::adjustSceneDynamics(int luxLevel) {
  int adjustedLuxLevel = luxLevel;
  if (adjustedLuxLevel < 0) {
    adjustedLuxLevel = 0;
  }
  if (adjustedLuxLevel > 100) {
    adjustedLuxLevel = 100;
  }
  dimmerLevel = adjustedLuxLevel;
  ambiancePreset = dimmerLevel > 65 ? "Highlight" : "Calm";
  motionReactive = dimmerLevel < 30;
  const std::string label = sceneLabel();
  if (label.find("Highlight") != std::string::npos) {
    motionReactive = false;
  }
}

std::string LightingSystem::sceneLabel() const {
  return ambiancePreset + "-" + std::to_string(dimmerLevel);
}
