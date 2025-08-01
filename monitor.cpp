#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayVitalAlert(std::string message)
{
    cout<<message;  
      for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

bool is_vital_within_range(float value,float min, float max)
{
  return value > min && value < max;
}

int isTemperatureOk(float temperature)
{
    if (is_vital_within_range(temperature,95,102)) {
    displayVitalAlert("Temperature is critical!");
    return 0;
}
return 1;
}

int isPulseOk(float temperature)
{
    if (is_vital_within_range(pulseRate,70,100)) {
    displayVitalAlert("Pulse Rate is out of range!");
    return 0;
}
return 1;
}

int isSpO2Ok(float temperature)
{
    if (spo2 < 90) {
    displayVitalAlert("Oxygen Saturation out of range!");
    return 0;
}
return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) && isPulseOk(pulseRate) && isSpO2Ok(spo2);
}