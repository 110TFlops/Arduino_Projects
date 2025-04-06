/************************************************************************
* @file     Weather_Monitor/DHT11_Interface.cpp
* @author   110TFlops
* @date     06/04/2025
* @version  1.0
* @link		https://github.com/110TFlops/Arduino_Projects
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#include "DHT11_Interface.h"

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "pinout.h"

DHT_Unified dht(DHT_PIN, DHT11);

static sensor_t temp_sensor;
static sensor_t humid_sensor;
static sensors_event_t event;

static uint32_t delayMS;
static float last_Temp = 0.0;
static float last_Humid = 0.0;

/***/
DHT11_Interface::DHT11_Interface(void){}

/***/
void DHT11_Interface::Init(void)
{
  dht.begin();
  dht.temperature().getSensor(&temp_sensor);
  dht.humidity().getSensor(&humid_sensor);

  delayMS = humid_sensor.min_delay / 1000;

  Sensor_Settle();
}

/***/
uint32_t DHT11_Interface::Get_Min_Delay(void)
{
  return delayMS;
}

/***/
float DHT11_Interface::Get_Temp(void)
{
  float val;
  dht.temperature().getEvent(&event);

  if(isnan(event.temperature))
  {
    val = -1000;
  }
  else
  {
    last_Temp = (last_Temp + event.temperature)/2;
    val = last_Temp;
  }

  return val;
}

/***/
float DHT11_Interface::Get_Humid(void)
{
  float val;
  dht.humidity().getEvent(&event);

  if(isnan(event.temperature))
  {
    val = -1000;
  }
  else
  {
    last_Humid = (last_Humid + event.relative_humidity)/2;
    val = last_Humid;
  }

  return val;
}

/**************************
* @brief Private Functions
***************************/
void DHT11_Interface::Sensor_Settle(void)
{
  float val;

  for(int i = 0; i < DHT11_SETTLE_REPS; i++)
  {
    dht.temperature().getEvent(&event);
    val = event.temperature;
    last_Temp = (last_Temp + val)/2;
    delay(DHT11_SETTLE_DELAY);
  }

  val = 0.0;

  for(int i = 0; i < DHT11_SETTLE_REPS; i++)
  {
    dht.humidity().getEvent(&event);
    val = event.relative_humidity;
    last_Humid = (last_Humid + val)/2;
    delay(DHT11_SETTLE_DELAY);
  }
}