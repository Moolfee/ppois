#include "domain/offers/ExperienceBundle/ExperienceBundle.h"

void ExperienceBundle::configureExperienceBundle(const std::shared_ptr<ExcursionPlan>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string ExperienceBundle::describeExperienceBundle() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string ExperienceBundle::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}