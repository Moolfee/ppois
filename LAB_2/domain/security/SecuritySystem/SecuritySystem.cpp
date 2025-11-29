#include "domain/security/SecuritySystem/SecuritySystem.h"

void SecuritySystem::synchronizeGuard(Guard &guard) {
  sensorGrid.registerMotionEvent(2);
  cameraNetwork.recalibrateAngles(1);
  lockdownEngaged = false;
  const std::string digest = securityDigest();
  const std::string guardReport = guard.guardSummary();
  if (guardReport.find("LOW") != std::string::npos) {
    throw SecurityBreachException(guardReport, 1, true);
  }
  if (digest.find("Secure") == std::string::npos) {
    lockdownEngaged = true;
  }
}

std::string SecuritySystem::securityDigest() const {
  return std::string("Secure-") + (lockdownEngaged ? "locked" : "open");
}
