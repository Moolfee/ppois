#include <gtest/gtest.h>
#include "domain/gallery/ArtworkLoanAgreement/ArtworkLoanAgreement.h"

TEST(ArtworkLoanAgreement, SealsForPainting) {
    ArtworkLoanAgreement agreement;
    Painting painting;
    ExhibitHall exhibitHall;
    painting.configureDisplay(exhibitHall);
    agreement.sealForPainting(painting);
    EXPECT_NE(agreement.agreementDigest().find("Clause"), std::string::npos);
}