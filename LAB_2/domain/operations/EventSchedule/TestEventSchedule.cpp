#include "domain/operations/EventSchedule/EventSchedule.h"
#include <gtest/gtest.h>

TEST(EventSchedule, BooksSlot) {
  EventSchedule schedule;
  schedule.bookSlot("Workshop");
  EXPECT_NE(schedule.eventDigest().find("Workshop"), std::string::npos);
}
