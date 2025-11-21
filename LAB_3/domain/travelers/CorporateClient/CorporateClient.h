#pragma once

#include <string>
#include <memory>
class Invoice;

class CorporateClient {
public:
    
    void configureCorporateClient(const std::shared_ptr<Invoice>& partner, int delta);

    
    std::string describeCorporateClient() const;

private:
    std::string statusLabel = "CorporateClientSeed";
    int priorityLevel = 1;
    std::shared_ptr<Invoice> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
