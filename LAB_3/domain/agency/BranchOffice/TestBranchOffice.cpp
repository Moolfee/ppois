#include <gtest/gtest.h>
#include "domain/agency/BranchOffice/BranchOffice.h"
#include "domain/agency/TravelAgencyProfile/TravelAgencyProfile.h"

TEST(BranchOffice, ConfiguresAndDescribes) {
    BranchOffice item;
    auto partner = std::make_shared<TravelAgencyProfile>();
    item.configureBranchOffice(partner, 2);
    EXPECT_TRUE(!item.describeBranchOffice().empty());
}