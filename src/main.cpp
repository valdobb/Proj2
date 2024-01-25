#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp180;

void setup() {
  Serial.begin(9600);
  if (!bmp180.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    
  }
}


void ReadTemperature() {
  float temperatureC = bmp180.readTemperature();
  String TempString = "Temp: " + String(temperatureC, 2) + "°C";
  Serial.println(TempString);
}

void ReadPressure() {
  float Pressure = bmp180.readPressure();
  String PressureString = "Pressure: " + String(Pressure, 2);
  Serial.println(PressureString);
}

void ReadAltitude() {
  float Altitude = bmp180.readAltitude();
  String AltitudeString = "Altitude: " + String(Altitude, 2);
  Serial.println(AltitudeString);
}

void ReadPressureSeaLevel() {
  float PressureSeaLevel = bmp180.readSealevelPressure();
  String PressureSeaLevelString = "PressureSeaLevel: " + String(PressureSeaLevel, 2);
  Serial.println(PressureSeaLevelString);
}

void ReadRealAltitude() {
  float Altitude = bmp180.readAltitude(101500);
  String AltitudeString = "RealAltitude: " + String(Altitude, 2);
  Serial.println(AltitudeString);
}


void loop() {
  ReadTemperature();
  ReadPressure();
  ReadAltitude();
  ReadPressureSeaLevel();
  ReadRealAltitude();
  delay(1000); // Adjust the delay based on your application requirements
}

