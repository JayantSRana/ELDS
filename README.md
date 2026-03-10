🌍 Landslide Monitoring & Early Warning System

An IoT and AI-based disaster monitoring system designed to detect early warning signs of landslides by analyzing environmental sensor data and satellite imagery.

The system integrates ESP32-based sensor monitoring with deep learning–based satellite image analysis to improve landslide detection and risk assessment.

📌 Project Overview

The Landslide Monitoring & Early Warning System continuously monitors environmental conditions in landslide-prone areas using multiple sensors and machine learning models.

The system:

Collects real-time environmental data

Detects ground movement and abnormal conditions

Generates early warning alerts

Uses deep learning segmentation models to detect landslide-prone regions from satellite images

This project is developed using ESP32 (Arduino Mode) and simulated on Wokwi, with a U-Net deep learning model for landslide detection.

🎯 Objectives

Detect early signs of landslides

Monitor rainfall, soil moisture, vibration, and pressure

Provide real-time alerts

Display live environmental data

Detect landslide-prone areas from satellite imagery

Reduce disaster risks through early warning systems

⚙️ System Architecture
1️⃣ IoT Monitoring System
Input Sensors

Soil Moisture Sensor

Rain Sensor

MPU6050 (Accelerometer & Gyroscope)

Pressure Sensor

DHT22 (Temperature & Humidity)

Processing Unit

ESP32 Microcontroller

Output Components

OLED Display (SSD1306)

Buzzer

Status LEDs

🟢 Normal

🟡 Warning

🔴 Critical

2️⃣ AI-Based Landslide Detection

A U-Net Deep Learning Model is used to detect landslide areas from satellite imagery.

Model Details

Architecture: U-Net Convolutional Neural Network

Input: Satellite images (RGB + NIR channels)

Output: Binary landslide risk mask

Framework: TensorFlow / Keras

🔄 Working Principle
IoT Monitoring

Sensors continuously collect environmental data.

ESP32 reads sensor values.

Data is compared with predefined thresholds.

Based on risk level:

Status	Action
🟢 Normal	Green LED
🟡 Warning	Yellow LED
🔴 Critical	Red LED + Buzzer

Data is displayed on the OLED screen.

AI Landslide Detection

Satellite image is uploaded.

Image is resized and normalized.

The trained U-Net model predicts landslide regions.

A segmentation mask highlights landslide areas.

Results are visualized using overlays.

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

SSD1306 OLED Display

Buzzer

LEDs

Connecting wires

💻 Software Requirements
IoT Development

Arduino IDE

ESP32 Board Support

Wokwi Simulator

Required Libraries

Adafruit GFX

Adafruit SSD1306

Adafruit MPU6050

Adafruit Unified Sensor

DHT Sensor Library

Machine Learning

Python 3

TensorFlow / Keras

OpenCV

NumPy

Matplotlib

Albumentations

🚀 Running the IoT Simulation (Wokwi)

Open Wokwi Simulator

Select ESP32 (Arduino Mode)

Add required components

Upload:

sketch.ino

diagram.json

libraries.txt

Start simulation

🤖 Running the AI Model

Open Google Colab or Jupyter Notebook

Upload the trained model:

unet_model_enhanced.h5

Upload a satellite image

Run prediction script

The model will generate:

Predicted landslide mask

Overlay visualization

Saved prediction image

🌐 Applications

Landslide-prone mountainous regions

Highway slope monitoring

Railway infrastructure safety

Mining areas

Remote hill villages

📈 Future Enhancements

GSM / SMS Alert System

Cloud Monitoring Dashboard

Mobile App Integration

Real-time satellite monitoring

Solar powered monitoring stations

🏆 Conclusion

This project demonstrates how IoT-based environmental monitoring combined with AI-powered satellite image analysis can help detect early signs of landslides and reduce disaster risks.

The system is cost-effective, scalable, and suitable for deployment in vulnerable regions.
