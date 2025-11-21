#include "domain/security/SecurityDrone/SecurityDrone.h"


void SecurityDrone::reportSweep(bool hardwareHealthy) {
    if (!hardwareHealthy) {
        throw EquipmentFailureException(droneId, 1, true);
    }
    activePatrol = !activePatrol;
    onboardLogger.captureIncident("Sweep");
    const std::string status = droneStatus();
    if (status.find("active") == std::string::npos) {
        activePatrol = true;
    }
}


std::string SecurityDrone::droneStatus() const {
    return droneId + "-active:" + (activePatrol ? "yes" : "no") + "-events:" + onboardLogger.summarizeIncidents();
}