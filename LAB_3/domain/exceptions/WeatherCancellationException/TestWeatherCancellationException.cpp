#include <gtest/gtest.h>
#include "domain/exceptions/WeatherCancellationException/WeatherCancellationException.h"

TEST(WeatherCancellationException, ProvidesDetails) {
    WeatherCancellationException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}