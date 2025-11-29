#include "domain/staff/AgencyManager/AgencyManager.h"

void AgencyManager::configureAgencyManager(
    const std::shared_ptr<BranchOffice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string AgencyManager::describeAgencyManager() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string AgencyManager::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
