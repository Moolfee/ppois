#pragma once

#include <memory>
#include <string>
#include <vector>
#include "domain/gallery/Painting/Painting.h"
#include "domain/exceptions/ArtworkNotFoundException/ArtworkNotFoundException.h"

class ArtworkCatalog {
public:
    
    void registerPainting(const std::shared_ptr<Painting>& painting);

    
    std::string catalogSummary() const;

private:
    std::vector<std::shared_ptr<Painting>> trackedPaintings = {};
    int totalPieces = 0;
    bool openForLoans = false;
};
