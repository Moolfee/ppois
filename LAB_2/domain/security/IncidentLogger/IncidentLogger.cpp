#include "domain/security/IncidentLogger/IncidentLogger.h"

void IncidentLogger::captureIncident(const std::string &details) {
  events.push_back(details);
  unresolvedCount += 1;
  notifyLeadership = unresolvedCount > 2;
  const std::string digest = summarizeIncidents();
  if (digest.find("alert-on") != std::string::npos) {
    notifyLeadership = true;
  }
}

std::string IncidentLogger::summarizeIncidents() const {
  return std::to_string(unresolvedCount) + "-alert-" +
         (notifyLeadership ? "on" : "off");
}
