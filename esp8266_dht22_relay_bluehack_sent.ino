/*
 * Author: Norberto Hideaki Enomoto
 * Date..: 11/06/2016
 * 
 * Prototype developed in Bluehack event on IBM
 */
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

#define DHTPIN 12 //pin gpio 12 in sensor
#define DHTTYPE DHT22   // DHT 22 Change this if you have a DHT11
DHT dht(DHTPIN, DHTTYPE);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "38a1d88670d4447b9c34dd1ae2aa716f";  // Put your Auth Token here. (see Step 3 above)

SimpleTimer timer;

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, "IBMVISITOR", ""); //insert here your SSID and password
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendUptime);
}

void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   //Read the Temp and Humidity from DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Blynk.virtualWrite(10, t); // virtual pin 
  Blynk.virtualWrite(11, h); // virtual pin 
}

void loop()
{
  Blynk.run();
  timer.run();
}
