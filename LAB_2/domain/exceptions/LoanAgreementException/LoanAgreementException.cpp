#include "domain/exceptions/LoanAgreementException/LoanAgreementException.h"


LoanAgreementException::LoanAgreementException(const std::string& partner, int clauses, bool freeze) : std::runtime_error("Loan agreement issue"), partnerName(partner), missingClauses(clauses), freezeShipment(freeze) {
}


std::string LoanAgreementException::describeIssue() const {
    return loanFlag() + "-partner:" + partnerName;
}


std::string LoanAgreementException::loanFlag() const {
    return std::to_string(missingClauses) + "-" + (freezeShipment ? "freeze" : "review");
}