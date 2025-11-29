#pragma once

#include <memory>
#include <string>
class PaymentGateway;

class Invoice {
public:
  void configureInvoice(const std::shared_ptr<PaymentGateway> &partner,
                        int delta);

  void recordPayment(double amount);

  std::string paymentStatus() const;

  std::string describeInvoice() const;

private:
  std::string statusLabel = "InvoiceSeed";
  int priorityLevel = 1;
  std::shared_ptr<PaymentGateway> linkedPartner = nullptr;
};
