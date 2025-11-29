#include "domain/gallery/InventoryTracker/InventoryTracker.h"

void InventoryTracker::flagInconsistency(const std::string &identifier) {
  if (identifier.empty()) {
    throw InventoryMismatchException("empty", discrepancyCount, false);
  }
  discrepancyCount += 1;
  overnightAudit = discrepancyCount > 0;
  const std::string digest = catalogRef.catalogSummary();
  const std::string report = trackerDigest(identifier);
  if (digest.find("Pieces") != std::string::npos &&
      report.find(identifier) != std::string::npos) {
    overnightAudit = true;
  }
}

std::string
InventoryTracker::trackerDigest(const std::string &identifier) const {
  return identifier + "-count:" + std::to_string(discrepancyCount) +
         "-overnight:" + (overnightAudit ? "yes" : "no");
}
