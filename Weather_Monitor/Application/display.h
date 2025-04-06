/************************************************************************
* @file     Weather_Monitor/display.h
* @author   AndrewJKnowles
* @date     30/03/2025
* @version  1.0
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define NUM_COLUMNS 16
#define NUM_ROWS    2

typedef enum
{
  DISABLE_LCD   = 0,
  ENABLE_LCD    = 1,
}pwr_mode_t;

class Display
{
  public:
    Display(void);
    void Init(pwr_mode_t pwr_mode);
    void Print(const char str[], uint8_t column, uint8_t row);
    void Print_Int(int val, uint8_t column, uint8_t row);
    void CLR(void);
    void Set_Pwr_Mode(pwr_mode_t pwr_mode);
    void Draw_Base_Screen(void);
    void Draw_Reading_Screen(void);
};

#endif //DISPLAY_H