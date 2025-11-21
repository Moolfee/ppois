#include <gtest/gtest.h>
#include "domain/security/MotionSensorGrid/MotionSensorGrid.h"

TEST(MotionSensorGrid, HandlesNormalAndIntenseEvents) {
    MotionSensorGrid sensorGrid;
    sensorGrid.registerMotionEvent(4);
    EXPECT_GT(sensorGrid.calculateNoiseBudget(), 0);

    sensorGrid.registerMotionEvent(50);
    EXPECT_GT(sensorGrid.calculateNoiseBudget(), 40);
}