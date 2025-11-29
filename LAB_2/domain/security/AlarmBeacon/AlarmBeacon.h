#pragma once

#include "domain/security/EmergencyExitControl/EmergencyExitControl.h"
#include <string>

class AlarmBeacon {
public:
  void broadcastAlert(const EmergencyExitControl &exitControl);

  std::string beaconSignature() const;

private:
  bool strobeEnabled = false;
  int volumePercent = 60;
  std::string zoneLabel = "Zone-A";
};
