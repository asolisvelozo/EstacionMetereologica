#include <DHT.h>

#define DHTPIN 3

#define DHTTYPE DHT11

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

Adafruit_BMP280 bme;

DHT dht(DHTPIN, DHTTYPE);
 
void setup() {


   Serial.begin(9600);
   
 
    dht.begin();
 
    bme.begin();
  }

 

 
void loop() {
  delay(10000);

    
  float h = dht.readHumidity();

  float t = dht.readTemperature();
 
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
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

 
}

