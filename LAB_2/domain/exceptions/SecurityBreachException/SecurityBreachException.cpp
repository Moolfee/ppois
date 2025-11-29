#include "domain/exceptions/SecurityBreachException/SecurityBreachException.h"

SecurityBreachException::SecurityBreachException(const std::string &snapshot,
                                                 int severity, bool lockdown)
    : std::runtime_error("Security breach"), guardSnapshot(snapshot),
      severityLevel(severity), lockdownRequired(lockdown) {}

std::string SecurityBreachException::describeIssue() const {
  return breachMarker() + "-snapshot:" + guardSnapshot;
}

std::string SecurityBreachException::breachMarker() const {
  return std::to_string(severityLevel) + "-" +
         (lockdownRequired ? "lock" : "monitor");
}
