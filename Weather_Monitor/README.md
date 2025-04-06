# **Weather Monitor**

| Field         | Comment         |
|---------------|-----------------|
| Platform      | Arduino Nano    |
| IDE           | Arduino v2.3.4  |
| Author        | 110TFlops		    |
| Date Created  | 06/04/2025      |
| Version       | v1.0            |
| Last Uppdated | |
| Updated By    | |
| License       | GPL-3.0 License |

<br><br>

## **Brief**
The Weather Monitor is interrupt driven by button 1. When initiated, the Nano reads the temperature and humidity from the DHT11 and displays its upon the LCD display. After a 30 second window has elapsed, the Arduino disables power to the LCD and enters deep sleep mode during which the current draw is reduced to ~1mA.

<br><br>

## **Hardware**

- Arduino Nano
- Breadboard PSU
- DHT11
- LCD Display
- NPN (x2)
- 1K resistor (x2)
- 10K resistor
- Tactile button
- 10K Potentiometer

<br><br>

### **Schematic**

![alt text](<Weather Monitor.drawio.png>)

<br><br>
