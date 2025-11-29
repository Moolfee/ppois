#include "domain/gallery/Statue/Statue.h"
#include <gtest/gtest.h>

TEST(Statue, EvaluatesPlacement) {
  Statue statue;
  ClimateControl climate;
  statue.evaluatePlacement(climate);
  EXPECT_NE(statue.postureReport().find("Balance"), std::string::npos);
}
