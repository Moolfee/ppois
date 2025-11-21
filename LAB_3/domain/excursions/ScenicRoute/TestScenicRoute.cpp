#include <gtest/gtest.h>
#include "domain/excursions/ScenicRoute/ScenicRoute.h"
#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"

TEST(ScenicRoute, ConfiguresAndDescribes) {
    ScenicRoute item;
    auto partner = std::make_shared<ExcursionPlan>();
    item.configureScenicRoute(partner, 2);
    EXPECT_TRUE(!item.describeScenicRoute().empty());
}