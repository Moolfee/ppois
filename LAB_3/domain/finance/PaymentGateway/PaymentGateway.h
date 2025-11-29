#pragma once

#include <memory>
#include <string>
class Invoice;

class PaymentGateway {
public:
  void configurePaymentGateway(const std::shared_ptr<Invoice> &partner,
                               int delta);

  void flagFraudAttempt(const std::string &reason);

  bool isOperational() const;

  std::string describePaymentGateway() const;

private:
  std::string statusLabel = "PaymentGatewaySeed";
  int priorityLevel = 1;
  std::shared_ptr<Invoice> linkedPartner = nullptr;
};
