#include <assert.h>
#include <iostream>
using namespace std;

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
   if(soc < 20 || soc > 80)
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
  return ( (bBatteryTemperatureIsOk(temperature) == true) && (bBatterySoCIsOk(soc) == true) && (bBatteryChargeRateIsOk(chargeRate) == true) );
}

void vTestBatteryTemperatureRanges()
{
  assert(bBatteryTemperatureIsOk(-1) == false);
  assert(bBatteryTemperatureIsOk(50) == false);
}

void vTestBatterySoCRanges()
{
  assert(bBatterySoCIsOk(0) == false);
  assert(bBatterySoCIsOk(100) == false);
} 

void vTestBatteryChargeRateRanges()
{
  assert(bBatteryChargeRateIsOk(1) == false);
  assert(bBatteryChargeRateIsOk(3.5) == false);
} 

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  
  // test for various temperature ranges.
  vTestBatteryTemperatureRanges();
  
  // test for various SoC ranges.
  vTestBatterySoCRanges();
  
  // test for various ranges of charge rate.
  vTestBatteryChargeRateRanges();
}
