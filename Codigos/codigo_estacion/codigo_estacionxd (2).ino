#include <DHT.h>

#define DHTPIN 3

#define DHTTYPE DHT11

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCL A4
#define BMP_SDA A5
#define BMP_CSB 11 
#define BMP_SDO 10

Adafruit_BMP280 bme;

DHT dht(DHTPIN, DHTTYPE);
 
void setup() {

   
   
   Serial.begin(9600);
   
 
    dht.begin();

    if (!bme.begin()) {  
      Serial.println("Could not find a valid BMP280 sensor, check wiring!");
  }
   
}

 

 
void loop() {
  

    
  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float p=bme.readPressure();
 
  if (isnan(h) || isnan(t) ) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
   
    
    float hic = dht.computeHeatIndex(t, h, false);
   
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print("Indice de calor: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print("Pressure = ");
    Serial.print(p);
    Serial.println(" Pa");
    delay(1000);
}

