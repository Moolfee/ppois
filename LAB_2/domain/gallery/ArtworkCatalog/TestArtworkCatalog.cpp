#include "domain/gallery/ArtworkCatalog/ArtworkCatalog.h"
#include <gtest/gtest.h>
#include <memory>

TEST(ArtworkCatalog, RegistersPainting) {
  ArtworkCatalog catalog;
  auto painting = std::make_shared<Painting>();
  ExhibitHall exhibitHall;
  painting->configureDisplay(exhibitHall);
  catalog.registerPainting(painting);
  EXPECT_NE(catalog.catalogSummary().find("Pieces"), std::string::npos);

  bool exceptionRaised = false;
  try {
    std::shared_ptr<Painting> missingPainting;
    catalog.registerPainting(missingPainting);
  } catch (const ArtworkNotFoundException &) {
    exceptionRaised = true;
  }
  EXPECT_TRUE(exceptionRaised);
}
