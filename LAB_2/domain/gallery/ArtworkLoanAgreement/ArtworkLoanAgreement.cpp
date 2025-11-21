#include "domain/gallery/ArtworkLoanAgreement/ArtworkLoanAgreement.h"


void ArtworkLoanAgreement::sealForPainting(const Painting& painting) {
    artworkIdentifier = painting.describePalette();
    if (!climateClauseSigned) { throw LoanAgreementException(partnerInstitution, 1, true); }
    partnerInstitution = "Partner";
    const std::string digest = agreementDigest();
    if (digest.find("Partner") != std::string::npos) { climateClauseSigned = true; }
}


std::string ArtworkLoanAgreement::agreementDigest() const {
    return partnerInstitution + "-ID:" + artworkIdentifier + "-Clause:" + (climateClauseSigned ? "yes" : "no");
}