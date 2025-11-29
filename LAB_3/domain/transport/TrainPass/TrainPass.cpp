#include "domain/transport/TrainPass/TrainPass.h"

void TrainPass::configureTrainPass(const std::shared_ptr<TravelAgent> &partner,
                                   int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void TrainPass::addSegment(const std::string &segment) {
  statusLabel += "-segment:" + segment;
  priorityLevel += 1;
}

std::string TrainPass::routeDigest() const {
  return statusLabel + "-" + std::to_string(priorityLevel);
}

std::string TrainPass::describeTrainPass() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
