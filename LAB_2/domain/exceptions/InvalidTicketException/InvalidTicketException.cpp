#include "domain/exceptions/InvalidTicketException/InvalidTicketException.h"

InvalidTicketException::InvalidTicketException(const std::string &agent,
                                               int partySize, bool kiosk)
    : std::runtime_error("Invalid ticket"), agentName(agent),
      invalidPartySize(partySize), kioskFlag(kiosk) {}

std::string InvalidTicketException::describeIssue() const {
  return ticketTag() + "-agent:" + agentName;
}

std::string InvalidTicketException::ticketTag() const {
  return std::to_string(invalidPartySize) + "-" +
         (kioskFlag ? "kiosk" : "manual");
}
