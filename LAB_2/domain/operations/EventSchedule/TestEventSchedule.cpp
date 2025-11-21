#include <gtest/gtest.h>
#include "domain/operations/EventSchedule/EventSchedule.h"

TEST(EventSchedule, BooksSlot) {
    EventSchedule schedule;
    schedule.bookSlot("Workshop");
    EXPECT_NE(schedule.eventDigest().find("Workshop"), std::string::npos);
}