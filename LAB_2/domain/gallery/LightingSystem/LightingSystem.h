#pragma once

#include <string>

class LightingSystem {
public:
  void adjustSceneDynamics(int luxLevel);

  std::string sceneLabel() const;

private:
  std::string ambiancePreset = "Neutral";
  int dimmerLevel = 50;
  bool motionReactive = true;
};
