#include "domain/staff/ComplianceOfficer/ComplianceOfficer.h"

void ComplianceOfficer::configureComplianceOfficer(
    const std::shared_ptr<TravelPolicy> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string ComplianceOfficer::describeComplianceOfficer() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
