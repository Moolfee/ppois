#include "domain/travelers/InsurancePlan/InsurancePlan.h"

void InsurancePlan::configureInsurancePlan(
    const std::shared_ptr<TravelPolicy> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void InsurancePlan::addCoverage(const std::string &coverage) {
  statusLabel += "-cover:" + coverage;
  priorityLevel += 1;
}

bool InsurancePlan::coversEmergency() const {
  return statusLabel.find("emergency") != std::string::npos;
}

std::string InsurancePlan::describeInsurancePlan() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
