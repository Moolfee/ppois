#include "domain/travelers/VisaApplication/VisaApplication.h"

void VisaApplication::configureVisaApplication(const std::shared_ptr<TravelAgent>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string VisaApplication::describeVisaApplication() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string VisaApplication::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}