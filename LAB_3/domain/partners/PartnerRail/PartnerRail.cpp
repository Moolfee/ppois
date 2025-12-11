#include "domain/partners/PartnerRail/PartnerRail.h"

void PartnerRail::configurePartnerRail(const std::shared_ptr<TrainPass> &partner,
                                       int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void PartnerRail::addRoute(const std::string &routeCode) {
  statusLabel += "-route:" + routeCode;
  priorityLevel += 1;
}

std::string PartnerRail::describePartnerRail() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
