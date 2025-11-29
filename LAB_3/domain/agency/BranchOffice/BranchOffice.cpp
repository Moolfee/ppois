#include "domain/agency/BranchOffice/BranchOffice.h"

void BranchOffice::configureBranchOffice(
    const std::shared_ptr<TravelAgencyProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void BranchOffice::rerouteCalls() { statusLabel += "-rerouted"; }

std::string BranchOffice::escalationPath() const {
  return statusLabel + "-priority:" + std::to_string(priorityLevel);
}

std::string BranchOffice::describeBranchOffice() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
