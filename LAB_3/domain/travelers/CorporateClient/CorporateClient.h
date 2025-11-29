#pragma once

#include <memory>
#include <string>
class Invoice;

class CorporateClient {
public:
  void configureCorporateClient(const std::shared_ptr<Invoice> &partner,
                                int delta);

  void renegotiateTerms(int step);

  std::string billingProfile() const;

  std::string describeCorporateClient() const;

private:
  std::string statusLabel = "CorporateClientSeed";
  int priorityLevel = 1;
  std::shared_ptr<Invoice> linkedPartner = nullptr;
};
