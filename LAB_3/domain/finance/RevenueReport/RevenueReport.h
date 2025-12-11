#pragma once

#include <memory>
#include <string>
class PaymentGateway;

class RevenueReport {
public:
  void configureRevenueReport(const std::shared_ptr<PaymentGateway> &partner,
                              int delta);

  void captureCycle(const std::string &cycleLabel);

  std::string describeRevenueReport() const;

private:
  std::string statusLabel = "RevenueReportSeed";
  int priorityLevel = 1;
  std::shared_ptr<PaymentGateway> linkedPartner = nullptr;
};
