#include "domain/partners/PartnerAirline/PartnerAirline.h"

void PartnerAirline::configurePartnerAirline(const std::shared_ptr<FlightTicket>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string PartnerAirline::describePartnerAirline() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string PartnerAirline::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}