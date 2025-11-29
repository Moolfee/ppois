#pragma once

#include "domain/exceptions/ArtworkNotFoundException/ArtworkNotFoundException.h"
#include "domain/gallery/Painting/Painting.h"
#include <memory>
#include <string>
#include <vector>

class ArtworkCatalog {
public:
  void registerPainting(const std::shared_ptr<Painting> &painting);

  std::string catalogSummary() const;

private:
  std::vector<std::shared_ptr<Painting>> trackedPaintings = {};
  int totalPieces = 0;
  bool openForLoans = false;
};
