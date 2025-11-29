#include "domain/agency/BranchOffice/BranchOffice.h"
#include "domain/staff/AgencyManager/AgencyManager.h"
#include <gtest/gtest.h>

TEST(AgencyManager, ConfiguresAndDescribes) {
  AgencyManager item;
  auto partner = std::make_shared<BranchOffice>();
  item.configureAgencyManager(partner, 2);
  EXPECT_TRUE(!item.describeAgencyManager().empty());
}
