📌 Project Overview

The Landslide Monitoring & Early Warning System is an IoT-based safety system designed to monitor environmental and ground conditions in landslide-prone areas.

The system continuously collects real-time data from multiple sensors and generates alerts when critical thresholds are exceeded.

This project is developed using ESP32 (Arduino Mode) and simulated on Wokwi.

🎯 Objective

Detect early signs of landslides

Monitor rainfall, soil moisture, pressure, and vibration

Provide real-time alert notifications

Display live environmental data

Reduce disaster risk through early warning

⚙️ System Architecture

Input Sensors:

Soil Moisture Sensor

Rain Sensor

MPU6050 (Accelerometer & Gyroscope)

Pressure Sensor

DHT22 (Temperature & Humidity)

Processing Unit:

ESP32 Microcontroller

Output Components:

OLED Display (SSD1306)

Buzzer

Status LEDs (Normal / Warning / Critical)

🔄 Working Principle

Sensors collect environmental data continuously.

ESP32 reads sensor values.

Data is compared with predefined threshold limits.

Based on conditions:

🟢 Normal → Green LED

🟡 Warning → Yellow LED

🔴 Critical → Red LED + Buzzer

Data is displayed on OLED screen.

(Optional) Data can be sent to cloud for remote monitoring.

📊 Alert Conditions
Parameter	Warning Level	Critical Level
Soil Moisture	> 45%	> 60%
Rainfall	Moderate	Heavy
Pressure	> 10 kPa	> 25 kPa
Humidity	High	> 85%
Motion	Sudden tilt	Strong acceleration
🛠️ Hardware Requirements

ESP32 Dev Module

Soil Moisture Sensor

Rain Sensor Module

MPU6050

Pressure Sensor

DHT22

SSD1306 OLED

Buzzer

LEDs

Connecting Wires

💻 Software Requirements

Wokwi Simulator

Arduino IDE (ESP32 Board Support)

Required Libraries:

Adafruit GFX

Adafruit SSD1306

Adafruit MPU6050

Adafruit Unified Sensor

DHT Sensor Library

🚀 How to Run (Wokwi)

Open Wokwi

Select ESP32 (Arduino Mode)

Add required components

Paste sketch.ino

Add diagram.json

Add libraries.txt

Start simulation

🌐 Applications

Landslide-prone hill areas

Road & railway slope monitoring

Mining regions

Remote mountainous villages

📈 Future Enhancements

GSM/SMS Alert System

Cloud Dashboard Monitoring

Mobile App Integration

AI-based Landslide Prediction

Solar Powered System

🏆 Conclusion

This project demonstrates how IoT-based real-time monitoring systems can help in disaster prevention by detecting early warning signs of landslides.

It is cost-effective, scalable, and suitable for deployment in vulnerable regions.
