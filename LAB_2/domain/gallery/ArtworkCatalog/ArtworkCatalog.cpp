#include "domain/gallery/ArtworkCatalog/ArtworkCatalog.h"


void ArtworkCatalog::registerPainting(const std::shared_ptr<Painting>& painting) {
    if (!painting) { throw ArtworkNotFoundException("Missing", totalPieces, true); }
    trackedPaintings.push_back(painting);
    totalPieces = static_cast<int>(trackedPaintings.size());
    openForLoans = totalPieces > 2;
}


std::string ArtworkCatalog::catalogSummary() const {
    return "Pieces:" + std::to_string(totalPieces) + "-Loans:" + (openForLoans ? "yes" : "no");
}