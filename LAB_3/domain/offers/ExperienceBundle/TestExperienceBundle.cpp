#include <gtest/gtest.h>
#include "domain/offers/ExperienceBundle/ExperienceBundle.h"
#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"

TEST(ExperienceBundle, ConfiguresAndDescribes) {
    ExperienceBundle item;
    auto partner = std::make_shared<ExcursionPlan>();
    item.configureExperienceBundle(partner, 2);
    EXPECT_TRUE(!item.describeExperienceBundle().empty());
}