#include "domain/staff/TravelAgent/TravelAgent.h"
#include "domain/travelers/VisaApplication/VisaApplication.h"
#include <gtest/gtest.h>

TEST(VisaApplication, ConfiguresAndDescribes) {
  VisaApplication item;
  auto partner = std::make_shared<TravelAgent>();
  item.configureVisaApplication(partner, 2);
  EXPECT_TRUE(!item.describeVisaApplication().empty());
}
