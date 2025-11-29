#pragma once

#include <string>
#include <vector>

class CameraNetwork {
public:
  void recalibrateAngles(int blindSpots);

  std::string describeCoverage() const;

private:
  int activeCameras = 12;
  std::vector<std::string> zones = {};
  bool hdEnabled = true;
};
