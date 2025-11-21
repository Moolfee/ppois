#pragma once

#include <string>
#include <vector>
#include "domain/staff/Guard/Guard.h"

class KeyCardLock {
public:
    
    void grantAccess(const Guard& guard);

    
    std::string lockSignature() const;

private:
    std::string doorName = "Vault";
    std::vector<std::string> permittedRoles = {};
    bool auditEnabled = false;
};
