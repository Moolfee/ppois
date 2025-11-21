#include "domain/security/MotionSensorGrid/MotionSensorGrid.h"


void MotionSensorGrid::registerMotionEvent(int magnitude) {
    sensorSensitivity.push_back(magnitude);
    triggeredCount += magnitude > 5 ? 2 : 1;
    silentMode = magnitude < 3;
    const int noise = calculateNoiseBudget();
    if (noise > 40) {
        silentMode = false;
    }
}


int MotionSensorGrid::calculateNoiseBudget() const {
    int total = 0;
    for (int reading : sensorSensitivity) {
        total += reading;
    }
    return total + triggeredCount;
}