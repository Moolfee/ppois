#include "domain/operations/TravelPolicy/TravelPolicy.h"

void TravelPolicy::configureTravelPolicy(const std::shared_ptr<ComplianceOfficer>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string TravelPolicy::describeTravelPolicy() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string TravelPolicy::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}