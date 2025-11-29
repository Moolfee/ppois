#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"

void TravelAgencyProfile::configureTravelAgencyProfile(
    const std::shared_ptr<TravelPolicy> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void TravelAgencyProfile::openMarket(const std::string &regionCode) {
  statusLabel += "-region:" + regionCode;
  priorityLevel += 2;
}

void TravelAgencyProfile::pauseMarket() { statusLabel += "-paused"; }

std::string TravelAgencyProfile::describeTravelAgencyProfile() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
