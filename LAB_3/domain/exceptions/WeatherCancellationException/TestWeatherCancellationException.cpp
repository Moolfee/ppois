#include "domain/exceptions/WeatherCancellationException/WeatherCancellationException.h"
#include <gtest/gtest.h>

TEST(WeatherCancellationException, ProvidesDetails) {
  WeatherCancellationException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
