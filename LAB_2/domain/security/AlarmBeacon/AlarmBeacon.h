#pragma once

#include <string>
#include "domain/security/EmergencyExitControl/EmergencyExitControl.h"

class AlarmBeacon {
public:
    
    void broadcastAlert(const EmergencyExitControl& exitControl);

    
    std::string beaconSignature() const;

private:
    bool strobeEnabled = false;
    int volumePercent = 60;
    std::string zoneLabel = "Zone-A";
};
