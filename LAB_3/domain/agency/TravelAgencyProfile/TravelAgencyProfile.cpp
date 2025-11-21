#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"

void TravelAgencyProfile::configureTravelAgencyProfile(const std::shared_ptr<TravelPolicy>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string TravelAgencyProfile::describeTravelAgencyProfile() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string TravelAgencyProfile::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}