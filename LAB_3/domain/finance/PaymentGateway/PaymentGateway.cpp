#include "domain/finance/PaymentGateway/PaymentGateway.h"

void PaymentGateway::configurePaymentGateway(
    const std::shared_ptr<Invoice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void PaymentGateway::flagFraudAttempt(const std::string &reason) {
  statusLabel += "-fraud-" + reason;
  priorityLevel += 2;
}

bool PaymentGateway::isOperational() const {
  return priorityLevel > 0 && statusLabel.find("fraud") == std::string::npos;
}

std::string PaymentGateway::describePaymentGateway() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
