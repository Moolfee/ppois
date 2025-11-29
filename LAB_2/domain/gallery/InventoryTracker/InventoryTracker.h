#pragma once

#include "domain/exceptions/InventoryMismatchException/InventoryMismatchException.h"
#include "domain/gallery/ArtworkCatalog/ArtworkCatalog.h"
#include <string>

class InventoryTracker {
public:
  void flagInconsistency(const std::string &identifier);

  std::string trackerDigest(const std::string &identifier) const;

private:
  ArtworkCatalog catalogRef = {};
  int discrepancyCount = 0;
  bool overnightAudit = false;
};
