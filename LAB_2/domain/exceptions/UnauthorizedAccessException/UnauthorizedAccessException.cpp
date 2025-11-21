#include "domain/exceptions/UnauthorizedAccessException/UnauthorizedAccessException.h"


UnauthorizedAccessException::UnauthorizedAccessException(const std::string& role, int badgeLength, bool alerted) : std::runtime_error("Unauthorized access: " + role), attemptedRole(role), badgeLengthChars(badgeLength), securityAlerted(alerted) {
}


std::string UnauthorizedAccessException::describeIssue() const {
    return panelTag() + "-role:" + attemptedRole;
}


std::string UnauthorizedAccessException::panelTag() const {
    return std::string(securityAlerted ? "ALARM" : "WARN") + "-" + std::to_string(badgeLengthChars);
}