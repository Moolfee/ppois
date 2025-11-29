#include "domain/visitors/TicketingAgent/TicketingAgent.h"
#include <gtest/gtest.h>

TEST(TicketingAgent, ValidatesTicket) {
  TicketingAgent agent;
  agent.validateTicket(3);
  EXPECT_NE(agent.sessionReport().find("tickets"), std::string::npos);
}

TEST(TicketingAgent, RejectsInvalidPartySize) {
  TicketingAgent agent;
  bool exceptionRaised = false;
  try {
    agent.validateTicket(0);
  } catch (const InvalidTicketException &) {
    exceptionRaised = true;
  }
  EXPECT_TRUE(exceptionRaised);
}
