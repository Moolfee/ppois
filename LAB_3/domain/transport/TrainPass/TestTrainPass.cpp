#include "domain/staff/TravelAgent/TravelAgent.h"
#include "domain/transport/TrainPass/TrainPass.h"
#include <gtest/gtest.h>

TEST(TrainPass, ConfiguresAndDescribes) {
  TrainPass item;
  auto partner = std::make_shared<TravelAgent>();
  item.configureTrainPass(partner, 2);
  EXPECT_TRUE(!item.describeTrainPass().empty());
}
