#pragma once

#include <stdexcept>
#include <string>

class PaymentProcessingException : public std::runtime_error {
public:
  PaymentProcessingException(const std::string &channel, int cents,
                             bool escalate);

  std::string describeIssue() const;

  std::string paymentSignature() const;

private:
  std::string paymentChannel = "terminal";
  int centsValue = 0;
  bool escalateAccounting = false;
};
