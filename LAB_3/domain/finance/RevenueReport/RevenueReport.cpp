#include "domain/finance/RevenueReport/RevenueReport.h"

void RevenueReport::configureRevenueReport(
    const std::shared_ptr<PaymentGateway> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void RevenueReport::captureCycle(const std::string &cycleLabel) {
  statusLabel += "-cycle:" + cycleLabel;
  priorityLevel += 1;
}

std::string RevenueReport::describeRevenueReport() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
