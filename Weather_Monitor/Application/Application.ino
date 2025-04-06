/************************************************************************
* @file     Weather_Monitor/Application.ino
* @author   110TFlops
* @date     06/04/2025
* @version  1.0
* @link		  https://github.com/110TFlops/Arduino_Projects
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#include <stdint.h>

#include "DHT11_Interface.h"
#include "display.h"
#include "pinout.h"
#include "pwr_mngr.h"

#define LOOP_DELAY        5000                        //mS
#define RUNNING_DURATION  (30 / (LOOP_DELAY / 1000))  //(x / (LOOP_DELAY / 1000)) - x is required delay in seconds

/**************************
* @brief Private Functions
***************************/
static void Wake_From_Sleep(void);
static void Interrupt_ISR(void);

typedef enum
{
  INIT_STATE,
  RUNNING_STATE,
  SLEEP_STATE
}device_state_t;

DHT11_Interface DHT11;
Display LCD_Display;
PWR_MNGR PWR_MNGR;

device_state_t device_state = INIT_STATE;
uint32_t myDelay;
uint16_t running_count;

void setup()
{
  attachInterrupt(INTERRUPT_0,Interrupt_ISR,CHANGE);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, 1);

  Wake_From_Sleep();
  device_state = RUNNING_STATE;
}

void loop()
{
  switch(device_state)
  {
    case INIT_STATE:
      Wake_From_Sleep();
      device_state = RUNNING_STATE;
      break;

    case RUNNING_STATE:
      LCD_Display.Print_Int((int)DHT11.Get_Temp(), 8, 0);
      LCD_Display.Print_Int((int)DHT11.Get_Humid(), 8, 1);

      if(++running_count == RUNNING_DURATION)
      {
        device_state = SLEEP_STATE;
      }
      else
      {
        delay(LOOP_DELAY);
      }
      break;

    case SLEEP_STATE:
      digitalWrite(LED_1, 0);
      LCD_Display.Set_Pwr_Mode(DISABLE_LCD);
      PWR_MNGR.Enter_Sleep();
      device_state = INIT_STATE;
      break;

    default:
      break;
  }
}

/***/
static void Wake_From_Sleep(void)
{
  LCD_Display.Init(ENABLE_LCD);
  DHT11.Init();
  delay(1000);
  myDelay = DHT11.Get_Min_Delay();
  running_count = 0;
  LCD_Display.Draw_Base_Screen();
}

/***/
static void Interrupt_ISR(void)
{
  digitalWrite(LED_1, 1);
}