#include "domain/operations/ScheduleBoard/ScheduleBoard.h"
#include "domain/transport/TrainPass/TrainPass.h"
#include <gtest/gtest.h>

TEST(ScheduleBoard, ConfiguresAndDescribes) {
  ScheduleBoard item;
  auto partner = std::make_shared<TrainPass>();
  item.configureScheduleBoard(partner, 2);
  EXPECT_TRUE(!item.describeScheduleBoard().empty());
}

TEST(ScheduleBoard, PostsUpdateAndChecksStaleness) {
  ScheduleBoard board;
  board.postUpdate("A1");
  EXPECT_TRUE(!board.isStale());
}
