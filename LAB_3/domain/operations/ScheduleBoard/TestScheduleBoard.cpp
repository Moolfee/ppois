#include <gtest/gtest.h>
#include "domain/operations/ScheduleBoard/ScheduleBoard.h"
#include "domain/transport/TrainPass/TrainPass.h"

TEST(ScheduleBoard, ConfiguresAndDescribes) {
    ScheduleBoard item;
    auto partner = std::make_shared<TrainPass>();
    item.configureScheduleBoard(partner, 2);
    EXPECT_TRUE(!item.describeScheduleBoard().empty());
}