#include "domain/finance/Invoice/Invoice.h"
#include "domain/finance/PaymentGateway/PaymentGateway.h"

void Invoice::configureInvoice(const std::shared_ptr<PaymentGateway> &partner,
                               int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void Invoice::recordPayment(double amount) {
  if (linkedPartner && !linkedPartner->isOperational()) {
    statusLabel += "-blocked";
    return;
  }
  if (amount > 0) {
    priorityLevel += static_cast<int>(amount);
    statusLabel += "-paid";
  } else {
    statusLabel += "-underpaid";
  }
}

std::string Invoice::paymentStatus() const {
  return statusLabel + "-balance:" + std::to_string(priorityLevel);
}

std::string Invoice::describeInvoice() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
