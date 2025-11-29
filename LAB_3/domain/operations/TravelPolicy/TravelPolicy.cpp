#include "domain/operations/TravelPolicy/TravelPolicy.h"

void TravelPolicy::configureTravelPolicy(
    const std::shared_ptr<ComplianceOfficer> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void TravelPolicy::enforceCompliance() {
  priorityLevel += 1;
  statusLabel += "-compliant";
}

void TravelPolicy::relaxPolicy() {
  if (priorityLevel > 0) {
    priorityLevel -= 1;
  }
  statusLabel += "-relaxed";
}

std::string TravelPolicy::describeTravelPolicy() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
