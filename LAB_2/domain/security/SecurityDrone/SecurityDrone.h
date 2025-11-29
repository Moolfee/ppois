#pragma once

#include "domain/exceptions/EquipmentFailureException/EquipmentFailureException.h"
#include "domain/security/IncidentLogger/IncidentLogger.h"
#include <string>

class SecurityDrone {
public:
  void reportSweep(bool hardwareHealthy);

  std::string droneStatus() const;

private:
  std::string droneId = "Scout-1";
  IncidentLogger onboardLogger = {};
  bool activePatrol = false;
};
