#pragma once

#include "domain/exceptions/SecurityBreachException/SecurityBreachException.h"
#include "domain/security/CameraNetwork/CameraNetwork.h"
#include "domain/security/MotionSensorGrid/MotionSensorGrid.h"
#include "domain/staff/Guard/Guard.h"
#include <string>

class SecuritySystem {
public:
  void synchronizeGuard(Guard &guard);

  std::string securityDigest() const;

private:
  CameraNetwork cameraNetwork = {};
  MotionSensorGrid sensorGrid = {};
  bool lockdownEngaged = true;
};
