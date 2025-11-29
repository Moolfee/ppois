#pragma once

#include <string>
#include <vector>

class MotionSensorGrid {
public:
  void registerMotionEvent(int magnitude);

  int calculateNoiseBudget() const;

private:
  std::vector<int> sensorSensitivity = {};
  bool silentMode = true;
  int triggeredCount = 0;
};
