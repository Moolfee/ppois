#pragma once

#include <string>
#include "domain/exceptions/InvalidTicketException/InvalidTicketException.h"

class TicketingAgent {
public:
    
    void validateTicket(int partySize);

    
    std::string sessionReport() const;

private:
    std::string agentName = "Kiosk";
    int issuedTickets = 0;
    bool kioskMode = true;
};
