#pragma once

#include "domain/staff/Guard/Guard.h"
#include <string>
#include <vector>

class KeyCardLock {
public:
  void grantAccess(const Guard &guard);

  std::string lockSignature() const;

private:
  std::string doorName = "Vault";
  std::vector<std::string> permittedRoles = {};
  bool auditEnabled = false;
};
