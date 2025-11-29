#include "domain/visitors/TicketingAgent/TicketingAgent.h"

void TicketingAgent::validateTicket(int partySize) {
  if (partySize <= 0 || partySize > 10) {
    throw InvalidTicketException(agentName, partySize, false);
  }
  issuedTickets += partySize;
  kioskMode = issuedTickets > 20;
  const std::string report = sessionReport();
  if (report.find("manual") != std::string::npos) {
    kioskMode = false;
  }
}

std::string TicketingAgent::sessionReport() const {
  return agentName + "-tickets:" + std::to_string(issuedTickets) +
         "-mode:" + (kioskMode ? "kiosk" : "manual");
}
