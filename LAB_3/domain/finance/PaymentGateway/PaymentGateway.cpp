#include "domain/finance/PaymentGateway/PaymentGateway.h"

void PaymentGateway::configurePaymentGateway(
    const std::shared_ptr<Invoice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string PaymentGateway::describePaymentGateway() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string PaymentGateway::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
