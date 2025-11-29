#pragma once

#include "domain/exceptions/UnauthorizedAccessException/UnauthorizedAccessException.h"
#include "domain/staff/StaffMember/StaffMember.h"
#include <string>

class AccessPanel {
public:
  void authorizeStaff(const StaffMember &staff);

  std::string auditLabel() const;

private:
  std::string panelLocation = "Gallery-East";
  std::string firmwareVersion = "v1.0";
  bool locked = true;
};
