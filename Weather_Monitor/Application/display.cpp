/************************************************************************
* @file     Weather_Monitor/display.cpp
* @author   110TFlops
* @date     06/04/2025
* @version  1.0
* @link		https://github.com/110TFlops/Arduino_Projects
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#include "display.h"

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "pinout.h"


LiquidCrystal lcd(LCD_RS_PIN, 
                  LCD_E_PIN, 
                  LCD_D4_PIN,
                  LCD_D5_PIN, 
                  LCD_D6_PIN, 
                  LCD_D7_PIN);

Display::Display(void){}

void Display::Init(pwr_mode_t pwr_mode)
{
  pinMode(LCD_PWR_EN_PIN, OUTPUT);
  Set_Pwr_Mode(pwr_mode);

  lcd.begin(NUM_COLUMNS, NUM_ROWS);
  Draw_Reading_Screen();
}

void Display::Print(const char str[], uint8_t column, uint8_t row)
{
  lcd.setCursor(column, row);
  lcd.print(str);
}

void Display::Print_Int(int val, uint8_t column, uint8_t row)
{
  char stringVal[10];
  memset(&stringVal[0], '\0', 10);
  sprintf(stringVal, "%.2d", val);
  lcd.setCursor(column, row);
  lcd.print(stringVal);
}

void Display::CLR(void)
{
  lcd.clear();
}

void Display::Set_Pwr_Mode(pwr_mode_t pwr_mode)
{
  if(pwr_mode == DISABLE_LCD)
  {
    CLR();
  }

  digitalWrite(LCD_PWR_EN_PIN, (uint8_t)pwr_mode);
  delay(100);
}

void Display::Draw_Base_Screen(void)
{
  CLR();
  Print("Temp :  -", 0, 0);
  Print("Humid:  -", 0, 1);
  Print("*C", 11, 0);
  Print("%", 11, 1);
}

void Display::Draw_Reading_Screen(void)
{
  CLR();
  Print("Reading...", 0, 0);
}