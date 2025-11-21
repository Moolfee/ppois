#include "domain/transport/CityPass/CityPass.h"

void CityPass::configureCityPass(const std::shared_ptr<ExcursionPlan>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string CityPass::describeCityPass() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string CityPass::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}