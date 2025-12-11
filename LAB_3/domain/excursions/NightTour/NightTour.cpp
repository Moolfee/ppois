#include "domain/excursions/NightTour/NightTour.h"

void NightTour::configureNightTour(
    const std::shared_ptr<ExcursionPlan> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void NightTour::addHighlight(const std::string &highlight) {
  statusLabel += "-highlight:" + highlight;
  priorityLevel += 1;
}

std::string NightTour::describeNightTour() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
