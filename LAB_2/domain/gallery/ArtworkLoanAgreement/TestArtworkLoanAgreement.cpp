#include "domain/gallery/ArtworkLoanAgreement/ArtworkLoanAgreement.h"
#include <gtest/gtest.h>

TEST(ArtworkLoanAgreement, SealsForPainting) {
  ArtworkLoanAgreement agreement;
  Painting painting;
  ExhibitHall exhibitHall;
  painting.configureDisplay(exhibitHall);
  agreement.sealForPainting(painting);
  EXPECT_NE(agreement.agreementDigest().find("Clause"), std::string::npos);
}
