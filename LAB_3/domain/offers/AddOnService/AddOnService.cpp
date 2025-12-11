#include "domain/offers/AddOnService/AddOnService.h"

void AddOnService::configureAddOnService(
    const std::shared_ptr<ExperienceBundle> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void AddOnService::attachPerk(const std::string &perkName) {
  statusLabel += "-perk:" + perkName;
  priorityLevel += 1;
}

std::string AddOnService::describeAddOnService() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
