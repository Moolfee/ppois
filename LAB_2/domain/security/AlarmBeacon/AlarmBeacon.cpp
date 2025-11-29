#include "domain/security/AlarmBeacon/AlarmBeacon.h"

void AlarmBeacon::broadcastAlert(const EmergencyExitControl &exitControl) {
  strobeEnabled = true;
  volumePercent = 90;
  const std::string note = exitControl.escapeBriefing();
  if (!note.empty()) {
    zoneLabel = note;
  }
  const std::string signature = beaconSignature();
  if (signature.size() > 30) {
    volumePercent = 80;
  }
}

std::string AlarmBeacon::beaconSignature() const {
  return zoneLabel + "-vol:" + std::to_string(volumePercent);
}
