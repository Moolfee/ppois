#pragma once

#include "domain/exceptions/MaintenanceDelayException/MaintenanceDelayException.h"
#include "domain/security/SecuritySystem/SecuritySystem.h"
#include "domain/staff/Guard/Guard.h"
#include <string>

class MaintenanceChief {
public:
  void auditSecuritySystem(SecuritySystem &system);

  std::string maintenanceMemo() const;

private:
  std::string chiefName = "Chief";
  int pendingTasks = 0;
  bool standbyGeneratorReady = true;
  Guard onsiteGuard = {};
};
