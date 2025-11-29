#pragma once

#include <stdexcept>
#include <string>

class LoanAgreementException : public std::runtime_error {
public:
  LoanAgreementException(const std::string &partner, int clauses, bool freeze);

  std::string describeIssue() const;

  std::string loanFlag() const;

private:
  std::string partnerName = "partner";
  int missingClauses = 0;
  bool freezeShipment = false;
};
