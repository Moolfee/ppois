#pragma once

#include <string>
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/exceptions/UnauthorizedAccessException/UnauthorizedAccessException.h"

class AccessPanel {
public:
    
    void authorizeStaff(const StaffMember& staff);

    
    std::string auditLabel() const;

private:
    std::string panelLocation = "Gallery-East";
    std::string firmwareVersion = "v1.0";
    bool locked = true;
};
