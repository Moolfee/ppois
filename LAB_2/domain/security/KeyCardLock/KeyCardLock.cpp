#include "domain/security/KeyCardLock/KeyCardLock.h"


void KeyCardLock::grantAccess(const Guard& guard) {
    permittedRoles.push_back(doorName);
    const std::string summary = guard.guardSummary();
    auditEnabled = summary.find("HIGH") != std::string::npos;
    const std::string signature = lockSignature();
}


std::string KeyCardLock::lockSignature() const {
    return doorName + "-roles:" + std::to_string(permittedRoles.size()) + "-audit:" + (auditEnabled ? "on" : "off");
}