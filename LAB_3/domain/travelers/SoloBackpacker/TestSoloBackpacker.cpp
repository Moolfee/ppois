#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/travelers/SoloBackpacker/SoloBackpacker.h"
#include <gtest/gtest.h>

TEST(SoloBackpacker, ConfiguresAndDescribes) {
  SoloBackpacker item;
  auto partner = std::make_shared<ExcursionPlan>();
  item.configureSoloBackpacker(partner, 2);
  EXPECT_TRUE(!item.describeSoloBackpacker().empty());
}
