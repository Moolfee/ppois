#include <gtest/gtest.h>
#include "domain/visitors/AudioGuide/AudioGuide.h"

TEST(AudioGuide, ActivatesNarration) {
    AudioGuide audioGuide;
    EXPECT_NE(audioGuide.previewNarration().find("Idle"), std::string::npos);
    audioGuide.activateNarration(4);
    EXPECT_NE(audioGuide.previewNarration().find("Segment-4"), std::string::npos);
}