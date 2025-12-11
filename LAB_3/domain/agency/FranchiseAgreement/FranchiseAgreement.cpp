#include "domain/agency/FranchiseAgreement/FranchiseAgreement.h"

void FranchiseAgreement::configureFranchiseAgreement(
    const std::shared_ptr<BranchOffice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void FranchiseAgreement::renewAgreement(int extraYears) {
  if (extraYears > 0) {
    priorityLevel += extraYears;
    statusLabel += "-renewed";
  } else {
    statusLabel += "-stalled";
  }
}

std::string FranchiseAgreement::describeFranchiseAgreement() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
