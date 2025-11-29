#include "domain/agency/BranchOffice/BranchOffice.h"
#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"
#include <gtest/gtest.h>

TEST(BranchOffice, ConfiguresAndDescribes) {
  BranchOffice item;
  auto partner = std::make_shared<TravelAgencyProfile>();
  item.configureBranchOffice(partner, 2);
  EXPECT_TRUE(!item.describeBranchOffice().empty());
}

TEST(BranchOffice, ReroutesAndEscalates) {
  BranchOffice office;
  office.rerouteCalls();
  EXPECT_NE(office.escalationPath().find("priority"), std::string::npos);
}
