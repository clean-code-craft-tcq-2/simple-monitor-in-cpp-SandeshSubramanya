#include <assert.h>
#include <iostream>
using namespace std;

bool bBatteryTemperatureIsOk(float temperature);
bool bBatterySoCIsOk(float soc);
bool bBatteryChargeRateIsOk(float chargeRate);

bool bBatteryTemperatureIsOk(float temperature)
{
  bool bRetBatteryTemperatureIsOk = true;
  if(temperature < 0 || temperature > 45) 
  {
    cout << "Temperature out of range!\n";
    bRetBatteryTemperatureIsOk = false;
  }

  return bRetBatteryTemperatureIsOk;
}

bool bBatterySoCIsOk(float soc)
{
   bool bRetBatterySoCIsOk = true;
   if(soc < 20 || soc > 80) {
   {
     cout << "State of Charge out of range!\n";
     bRetBatterySoCIsOk = false;
   }
     
   return bRetBatterySoCIsOk;
}

bool bBatteryChargeRateIsOk(float chargeRate)
{
  bool bRetChargeRateIsOk = true;
  
  if(chargeRate > 0.8)
  {
    cout << "Charge Rate out of range!\n";
    bRetChargeRateIsOk = false;
  }

  return bRetChargeRateIsOk;
}


bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return ( (bBatteryTemperatureIsOk == true) && (bBatterySoCIsOk == true) && (bBatteryChargeRateIsOk == true) )
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
