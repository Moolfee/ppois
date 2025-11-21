#include "domain/exceptions/PaymentProcessingException/PaymentProcessingException.h"


PaymentProcessingException::PaymentProcessingException(const std::string& channel, int cents, bool escalate) : std::runtime_error("Payment failure"), paymentChannel(channel), centsValue(cents), escalateAccounting(escalate) {
}


std::string PaymentProcessingException::describeIssue() const {
    return paymentSignature() + "-channel:" + paymentChannel;
}


std::string PaymentProcessingException::paymentSignature() const {
    return std::to_string(centsValue) + "-" + (escalateAccounting ? "ledger" : "warn");
}