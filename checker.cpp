#include <assert.h>
#include <iostream>
#include <cmath>
using namespace std;

#define MIN_BATTERYSOC_VALUE (float) 20
#define MAX_BATTERYSOC_VALUE (float) 80
#define SOC_TOLERANCE_FACTOR_FOR_EARLYWARNING 5 // 5%

typedef enum teBatteryParameterType     //te stands for type enum
{
    BATTERY_SOC = 0,
    BATTERY_TEMPERATURE,
    BATTERY_CHARGERATE
}eBatteryParamType;

/*bool bEarlyWarningNecessary(eBatteryParamType oBatteryParamType, float fValue)
{
    bool bRaiseWarning = false;
    
    if (oBatteryParamType ==  teBatteryParameterType::BATTERY_SOC)
    {
        //SOC 
        float fToleranceValue = (SOC_TOLERANCE_FACTOR_FOR_EARLYWARNING / 100.f ) * MAX_BATTERYSOC_VALUE;
        
        if( 
            (std::abs(fValue-MAX_BATTERYSOC_VALUE) <= fToleranceValue)
            ||
            (std::abs(fValue-MIN_BATTERYSOC_VALUE) <= fToleranceValue)
          )
          {
              bRaiseWarning = true;
          }
    }
    return bRaiseWarning;
}*/

bool bBatteryParameterIsOk(eBatteryParamType oBatteryParamType, float value)
{
  bool bRetBatteryParamterIsOk = true;
  
  if (oBatteryParamType ==  teBatteryParameterType::BATTERY_TEMPERATURE)
  {
    if(value < 0 || value > 45)
    {
        cout << "Temperature out of range!\n";
        bRetBatteryParamterIsOk = false;
    }
  }
  else if (oBatteryParamType ==  teBatteryParameterType::BATTERY_SOC)
  {
    if(value < 20 || value > 80)
    {
        cout << "State of Charge out of range!\n";
        bRetBatteryParamterIsOk = false;
    }  
  }
  return bRetBatteryParamterIsOk;
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
  return ( (bBatteryParameterIsOk(teBatteryParameterType::BATTERY_TEMPERATURE,temperature) == true) && (bBatteryParameterIsOk(teBatteryParameterType::BATTERY_SOC,soc) == true) && (bBatteryChargeRateIsOk(chargeRate) == true) );
}

void vTestBatteryTemperatureRanges()
{
  assert(bBatteryParameterIsOk(teBatteryParameterType::BATTERY_TEMPERATURE, -1) == false);
  assert(bBatteryParameterIsOk(teBatteryParameterType::BATTERY_TEMPERATURE, 50) == false);
}

void vTestBatterySoCRanges()
{
  assert(bBatteryParameterIsOk(teBatteryParameterType::BATTERY_SOC,0) == false);
  assert(bBatteryParameterIsOk(teBatteryParameterType::BATTERY_SOC,100) == false);
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
