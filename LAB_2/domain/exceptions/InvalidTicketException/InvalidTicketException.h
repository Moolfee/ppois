#pragma once

#include <stdexcept>
#include <string>

class InvalidTicketException : public std::runtime_error {
public:
    
    InvalidTicketException(const std::string& agent, int partySize, bool kiosk);

    
    std::string describeIssue() const;

    
    std::string ticketTag() const;

private:
    std::string agentName = "agent";
    int invalidPartySize = 0;
    bool kioskFlag = false;
};
