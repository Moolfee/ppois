#include "domain/offers/ExperienceBundle/ExperienceBundle.h"

void ExperienceBundle::configureExperienceBundle(
    const std::shared_ptr<ExcursionPlan> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void ExperienceBundle::addPerk(const std::string &perkName) {
  statusLabel += "-perk:" + perkName;
  priorityLevel += 1;
}

std::string ExperienceBundle::bundleSummary() const {
  return statusLabel + "-priority:" + std::to_string(priorityLevel);
}

std::string ExperienceBundle::describeExperienceBundle() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
