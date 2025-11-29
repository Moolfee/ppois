#include "domain/operations/ScheduleBoard/ScheduleBoard.h"

void ScheduleBoard::configureScheduleBoard(
    const std::shared_ptr<TrainPass> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void ScheduleBoard::postUpdate(const std::string &routeCode) {
  statusLabel += "-update:" + routeCode;
  priorityLevel += 1;
}

bool ScheduleBoard::isStale() const { return priorityLevel < 1; }

std::string ScheduleBoard::describeScheduleBoard() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
