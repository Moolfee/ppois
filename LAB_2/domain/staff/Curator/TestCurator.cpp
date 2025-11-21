#include <gtest/gtest.h>
#include "domain/staff/Curator/Curator.h"

TEST(Curator, PlansRestoration) {
    Curator curator;
    RestorationSpecialist specialist;
    curator.planRestoration(specialist);
    EXPECT_NE(curator.curatorialStatement().find("Curator"), std::string::npos);
}