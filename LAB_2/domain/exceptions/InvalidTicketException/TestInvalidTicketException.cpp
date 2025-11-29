#include "domain/exceptions/InvalidTicketException/InvalidTicketException.h"
#include <gtest/gtest.h>

TEST(InvalidTicketException, DescribesTicketIssue) {
  InvalidTicketException exceptionInstance("Desk", 12, false);
  EXPECT_NE(exceptionInstance.describeIssue().find("Desk"), std::string::npos);
  InvalidTicketException kioskInstance("Kiosk", 15, true);
  EXPECT_NE(kioskInstance.ticketTag().find("kiosk"), std::string::npos);
}
