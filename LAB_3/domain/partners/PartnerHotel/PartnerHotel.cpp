#include "domain/partners/PartnerHotel/PartnerHotel.h"

void PartnerHotel::configurePartnerHotel(
    const std::shared_ptr<ResortProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void PartnerHotel::setSeasonalRate(int factor) {
  priorityLevel += factor;
  statusLabel += "-seasonal";
}

std::string PartnerHotel::conciergeLine() const { return statusLabel + "-vip"; }

std::string PartnerHotel::describePartnerHotel() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
