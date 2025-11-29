#include "domain/gallery/GalleryMap/GalleryMap.h"

void GalleryMap::updateWing(const std::string &wingName) {
  highlightedWings.push_back(wingName);
  revisionTag = wingName;
  printable = highlightedWings.size() <= 4;
  const std::string digest = mapDigest();
  if (digest.size() > 30) {
    printable = false;
  }
}

std::string GalleryMap::mapDigest() const {
  return revisionTag + "-print:" + (printable ? "yes" : "no") +
         "-count:" + std::to_string(highlightedWings.size());
}
