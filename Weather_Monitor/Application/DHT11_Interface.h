/************************************************************************
* @file     Weather_Monitor/DHT11_Interface.h
* @author   110TFlops
* @date     06/04/2025
* @version  1.0
* @link		https://github.com/110TFlops/Arduino_Projects
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#ifndef DHT11_INTERFACE_H
#define DHT11_INTERFACE_H

#include <stdint.h>

#define DHT11_SETTLE_REPS   10
#define DHT11_SETTLE_DELAY  500 //mS

class DHT11_Interface
{
  public:
    DHT11_Interface(void);
    void Init(void);
    uint32_t Get_Min_Delay(void);
    float Get_Temp(void);
    float Get_Humid(void);

  private:
  void Sensor_Settle(void);
};

#endif //DHT11_INTERFACE_H