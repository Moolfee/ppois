#include "domain/exceptions/VisitorLimitExceededException/VisitorLimitExceededException.h"


VisitorLimitExceededException::VisitorLimitExceededException(const std::string& guide, int party, bool escort) : std::runtime_error("Visitor limit exceeded"), guideName(guide), partyCount(party), requireEscort(escort) {
}


std::string VisitorLimitExceededException::describeIssue() const {
    return visitorFlag() + "-guide:" + guideName;
}


std::string VisitorLimitExceededException::visitorFlag() const {
    return std::to_string(partyCount) + "-" + (requireEscort ? "escort" : "monitor");
}