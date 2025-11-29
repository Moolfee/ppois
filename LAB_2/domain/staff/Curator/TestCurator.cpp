#include "domain/staff/Curator/Curator.h"
#include <gtest/gtest.h>

TEST(Curator, PlansRestoration) {
  Curator curator;
  RestorationSpecialist specialist;
  curator.planRestoration(specialist);
  EXPECT_NE(curator.curatorialStatement().find("Curator"), std::string::npos);
}
