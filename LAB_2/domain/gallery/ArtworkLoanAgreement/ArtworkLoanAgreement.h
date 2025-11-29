#pragma once

#include "domain/exceptions/LoanAgreementException/LoanAgreementException.h"
#include "domain/gallery/Painting/Painting.h"
#include <string>

class ArtworkLoanAgreement {
public:
  void sealForPainting(const Painting &painting);

  std::string agreementDigest() const;

private:
  std::string partnerInstitution = "LocalMuseum";
  std::string artworkIdentifier = "Pending";
  bool climateClauseSigned = true;
};
