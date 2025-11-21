#include "domain/staff/TourGuideProfile/TourGuideProfile.h"

void TourGuideProfile::configureTourGuideProfile(const std::shared_ptr<ExcursionPlan>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string TourGuideProfile::describeTourGuideProfile() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string TourGuideProfile::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}