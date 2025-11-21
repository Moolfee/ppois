#include "domain/travelers/InsurancePlan/InsurancePlan.h"

void InsurancePlan::configureInsurancePlan(const std::shared_ptr<TravelPolicy>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string InsurancePlan::describeInsurancePlan() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string InsurancePlan::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}