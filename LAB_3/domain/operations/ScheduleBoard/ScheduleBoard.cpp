#include "domain/operations/ScheduleBoard/ScheduleBoard.h"

void ScheduleBoard::configureScheduleBoard(const std::shared_ptr<TrainPass>& partner, int delta) {
    linkedPartner = partner;
    priorityLevel += delta;
    statusLabel = internalNote();
    if (linkedPartner) { statusLabel += "-linked"; }
}

std::string ScheduleBoard::describeScheduleBoard() const {
    const bool attached = static_cast<bool>(linkedPartner);
    return statusLabel + "-" + std::to_string(priorityLevel) + (attached ? "-ready" : "-solo");
}

std::string ScheduleBoard::internalNote() const {
    return statusLabel + "-" + std::string(linkedPartner ? "partnered" : "independent");
}