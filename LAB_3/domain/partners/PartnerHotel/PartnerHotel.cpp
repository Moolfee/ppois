#include "domain/partners/PartnerHotel/PartnerHotel.h"

void PartnerHotel::configurePartnerHotel(const std::shared_ptr<ResortProfile>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string PartnerHotel::describePartnerHotel() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string PartnerHotel::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}