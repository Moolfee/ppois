#include "domain/resort/SpaPackage/SpaPackage.h"

void SpaPackage::configureSpaPackage(
    const std::shared_ptr<ResortProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void SpaPackage::addTreatment(const std::string &treatment) {
  statusLabel += "-treatment:" + treatment;
  priorityLevel += 1;
}

std::string SpaPackage::describeSpaPackage() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
