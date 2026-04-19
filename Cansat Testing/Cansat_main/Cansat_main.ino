#include "Wire.h"
#include <BMP280.h>
#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>

//definitions for BMP
BMP280 bmp280;

//definitions for accelerometer
Adafruit_ICM20948 icm;
uint16_t measurement_delay_us = 65535; // Delay between measurements for testing
#define ICM_CS 11


void setup() {
  //Serial init
  Serial.begin(9600);

  
  //Init ICM accelerometer
  if (!icm.begin_SPI(ICM_CS)) {
    // if (!icm.begin_SPI(ICM_CS, ICM_SCK, ICM_MISO, ICM_MOSI)) {
    Serial.println("Failed to find ICM20948 chip");
    while (1) {
      delay(10);
    }
  }

  // Init bmp
  bmp280.begin();
  icm.setAccelRange(ICM20948_ACCEL_RANGE_16_G);
  icm.setGyroRange(ICM20948_GYRO_RANGE_500_DPS);
  icm.setAccelRateDivisor(4095);
  uint16_t accel_divisor = icm.getAccelRateDivisor();
  float accel_rate = 1125 / (1.0 + accel_divisor);

  icm.setGyroRateDivisor(255);
  uint8_t gyro_divisor = icm.getGyroRateDivisor();
  float gyro_rate = 1100 / (1.0 + gyro_divisor);
  icm.setMagDataRate(AK09916_MAG_DATARATE_10_HZ);


}

void loop() {
  // Loop bmp
  uint32_t pressure = bmp280.getPressure();
  float temperature = bmp280.getTemperature();


  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t mag;
  sensors_event_t temp;
  icm.getEvent(&accel, &gyro, &temp, &mag);


}
