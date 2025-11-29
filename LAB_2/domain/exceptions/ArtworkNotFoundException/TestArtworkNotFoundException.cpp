#include "domain/exceptions/ArtworkNotFoundException/ArtworkNotFoundException.h"
#include <gtest/gtest.h>

TEST(ArtworkNotFoundException, DescribesIssue) {
  ArtworkNotFoundException exceptionInstance("WingA", 2, true);
  EXPECT_NE(exceptionInstance.describeIssue().find("WingA"), std::string::npos);
  ArtworkNotFoundException noticeInstance("HallB", 1, false);
  EXPECT_NE(noticeInstance.catalogTag().find("NOTICE"), std::string::npos);
}
