# Smart-Gas-Guard
Arduino-based LPG Leak and Weight Monitoring System using MQ2 Gas Sensor and HX711 Load Cell.



An Arduino-based smart safety system designed to detect LPG gas leakage and continuously monitor the weight of an LPG cylinder.

## Features

- LPG gas leak detection using MQ2 sensor
- Cylinder weight monitoring using HX711 load cell
- LCD display for real-time status
- Buzzer alarm during gas leakage
- LED status indication
- Relay control for safety operation

## Hardware Components

- Arduino Uno
- MQ2 Gas Sensor
- HX711 Load Cell Amplifier
- Load Cell
- 16x2 I2C LCD
- Relay Module
- Buzzer
- LEDs
- Connecting Wires
- Power Supply

## Software

- Arduino IDE
- Embedded C++

## Project Structure

```
Smart-Gas-Guard/
│
├── Gas_Leak_Detection.ino
├── Weight_Monitoring.ino
├── README.md
└── LICENSE
```

## Working

The MQ2 sensor continuously monitors LPG gas concentration. If the gas concentration exceeds the threshold, the system activates the buzzer, turns on the red LED, displays an alert on the LCD, and energizes the relay.

The HX711 module measures the cylinder weight using a load cell and displays the weight through the Serial Monitor.

## Applications

- Homes
- Hotels
- Restaurants
- Industrial Kitchens
- LPG Storage Areas

## Authors

- Sinduja B
- Team: Deadline Dominators

---
