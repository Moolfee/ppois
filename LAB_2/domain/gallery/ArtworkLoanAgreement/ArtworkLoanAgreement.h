#pragma once

#include <string>
#include "domain/gallery/Painting/Painting.h"
#include "domain/exceptions/LoanAgreementException/LoanAgreementException.h"

class ArtworkLoanAgreement {
public:
    
    void sealForPainting(const Painting& painting);

    
    std::string agreementDigest() const;

private:
    std::string partnerInstitution = "LocalMuseum";
    std::string artworkIdentifier = "Pending";
    bool climateClauseSigned = true;
};
