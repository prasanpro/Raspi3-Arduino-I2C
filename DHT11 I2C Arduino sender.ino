#include "DHT.h"
#include <Wire.h>
#define SLAVE_ADDRESS 0x04
#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);
//Define temperature variable as character array so that it'll easy to send data over I2C to Raspberry
char t[5];

void setup() {
  Serial.begin(9600);
    // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);
  
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();
  //convert double to string, details here: http://www.hobbytronics.co.uk/arduino-float-vars
  dtostrf(temp,5,2,t);

  //Print data on Arduino monitor
  Serial.print("T:");
  Serial.print(t);
  Serial.println("*C ");
  Wire.onRequest(requestEvent);
}

int index = 0;
  
void requestEvent()
{
 //Send data one by one
 Wire.write(t[index]);
    ++index;
    if (index >= 5) {
         index = 0;
    }
}
