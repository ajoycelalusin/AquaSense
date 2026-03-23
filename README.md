# AquaSense - Embedded Flood Monitoring System 

AquaSense is an embedded system that monitors water levels and soil moisture, automates pumping and irrigation, and provides alerts via an LCD and buzzer. It prevents flooding by storing excess water and releases it for irrigation when needed. Designed for households in flood-prone and agricultural areas, AquaSense demonstrates how low-cost, small-scale technology can enhance water management, support sustainability, and improve community resilience.

Components and Arduino Connections
Water Level Sensor → connected to analog pin A0
Soil Moisture Sensor → connected to analog pin A1
Buzzer → connected to digital pin D8
Relay Module for Water Level Pump → connected to digital pin D7
Relay Module for Soil Level Pump → connected to digital pin D6
I2C LCD Display
SDA → connected to SDA pin on Arduino
SCL → connected to SCL pin on Arduino
9V Battery → connected to the VCC and Ground of the relay modules
Common Ground → ensure all components share a common ground

## Features
- Monitor water levels in real-time
- Display the water level in lcd 
- Early warning notifications for floods
- Automated irrigation control
