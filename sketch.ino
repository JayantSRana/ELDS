#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// ================= OLED =================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ================= DHT22 =================
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ================= MPU6050 =================
Adafruit_MPU6050 mpu;

// ================= PINS =================
#define SOIL_PIN 34
#define PRESSURE_PIN 35
#define RAIN_PIN 25

#define LED_NORMAL 2
#define LED_WARNING 16
#define LED_CRITICAL 17
#define BUZZER_PIN 15

// ================= Thresholds =================
#define ACCEL_THRESHOLD 15.0
#define SOIL_WARN 45
#define SOIL_CRIT 60
#define PRESSURE_WARN 10
#define PRESSURE_CRIT 25
#define HUMIDITY_CRIT 85
#define RAIN_CRIT 50

volatile int rainPulses = 0;
unsigned long lastISR = 0;

// ============== Rain Interrupt ==============
void IRAM_ATTR rainPulseISR() {
  unsigned long now = millis();
  if (now - lastISR > 15) {
    rainPulses++;
    lastISR = now;
  }
}

void setup() {

  Serial.begin(115200);
  Wire.begin(21, 22);

  dht.begin();

  // MPU Init
  if (!mpu.begin()) {
    Serial.println("❌ MPU6050 not found!");
    while (1);
  }

  // OLED Init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("❌ OLED failed");
    while (1);
  }

  pinMode(LED_NORMAL, OUTPUT);
  pinMode(LED_WARNING, OUTPUT);
  pinMode(LED_CRITICAL, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(RAIN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RAIN_PIN), rainPulseISR, FALLING);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  Serial.println("🌍 Landslide Monitoring System Started");
}

void loop() {

  // ===== Soil =====
  int soilADC = analogRead(SOIL_PIN);
  float soilMoisture = map(soilADC, 0, 4095, 0, 100);

  // ===== Pressure =====
  int pressureADC = analogRead(PRESSURE_PIN);
  float voltage = (pressureADC / 4095.0) * 3.3;
  float pressure = (voltage - 0.5) * 10.0;

  // ===== DHT =====
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // ===== Rain =====
  float rainfall = rainPulses * 0.2;

  // ===== MPU =====
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float accelMagnitude = sqrt(
    a.acceleration.x * a.acceleration.x +
    a.acceleration.y * a.acceleration.y +
    a.acceleration.z * a.acceleration.z
  );

  bool motionDetected = accelMagnitude > ACCEL_THRESHOLD;

  // ===== Status =====
  String status = "Normal";

  if (pressure > PRESSURE_CRIT || soilMoisture > SOIL_CRIT ||
      rainfall > RAIN_CRIT || humidity > HUMIDITY_CRIT || motionDetected) {
    status = "CRITICAL";
  }
  else if (pressure > PRESSURE_WARN || soilMoisture > SOIL_WARN) {
    status = "WARNING";
  }

  // ===== LED + Buzzer =====
  digitalWrite(LED_NORMAL, status == "Normal");
  digitalWrite(LED_WARNING, status == "WARNING");
  digitalWrite(LED_CRITICAL, status == "CRITICAL");
  digitalWrite(BUZZER_PIN, status == "CRITICAL");

  // ===== OLED =====
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("Soil: "); display.print(soilMoisture); display.println("%");
  display.print("Press: "); display.print(pressure, 1); display.println("kPa");
  display.print("Rain: "); display.print(rainfall, 1); display.println("mm");
  display.print("Hum: "); display.print(humidity); display.println("%");
  display.print("Temp: "); display.print(temperature); display.println("C");
  display.print("Motion: "); display.println(motionDetected ? "YES" : "NO");
  display.print("Status: "); display.println(status);

  display.display();

  // ===== Serial =====
  Serial.print("Status: ");
  Serial.println(status);

  delay(1000);
}