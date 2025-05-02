/************************************************************************
* @file     Autonomus_Gardener/pinout.h
* @author   110TFlops
* @date     26/03/2025
* @version  1.0
* @link		  https://github.com/110TFlops/Arduino_Projects
* @brief    Available under the GNU GENERAL PUBLIC LICENSE without any 
*           warranty or liability
**************************************************************************/

#ifndef PINOUT_H
#define PINOUT_H

#include "hardware_version.h"

#if defined(HARDWARE_VERSION) && (HARDWARE_VERSION == 0)
#warning "110TFlops: Hardware Version 0 (Prototype) Specified"
#define INTERRUPT_0         0             //pin D2
#define LED_1               13
#define SOIL_MOISTURE_PIN   A1  
#define RELAY_SWITCH        PIN_A0

#elif defined(HARDWARE_VERSION) && (HARDWARE_VERSION == 1) 
#warning "110TFlops: Hardware Version 1 Specified"
#define INTERRUPT_0         0             //pin D2
#define PUMP_EN             4
#define V_SENSE_EN          5
#define LED_1               13
#define SOIL_MOISTURE_PIN   A0 

#else
#error "110TFlops: Error - Hardware Version Unknown"
#endif //HARDWARE_VERSION
#endif //PINOUT_H