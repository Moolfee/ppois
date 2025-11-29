#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/offers/ExperienceBundle/ExperienceBundle.h"
#include <gtest/gtest.h>

TEST(ExperienceBundle, ConfiguresAndDescribes) {
  ExperienceBundle item;
  auto partner = std::make_shared<ExcursionPlan>();
  item.configureExperienceBundle(partner, 2);
  EXPECT_TRUE(!item.describeExperienceBundle().empty());
}

TEST(ExperienceBundle, AddsPerkAndSummarizes) {
  ExperienceBundle bundle;
  bundle.addPerk("spa");
  EXPECT_NE(bundle.bundleSummary().find("perk:spa"), std::string::npos);
}
