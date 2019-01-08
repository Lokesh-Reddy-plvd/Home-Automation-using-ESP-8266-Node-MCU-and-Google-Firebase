#include <FirebaseArduino.h>
#include "DHT.h"

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "lokesh-36079.firebaseio.com"
#define WIFI_SSID "Lokesh" // Change the name of your WIFI
#define WIFI_PASSWORD "123454321" // Change the password of your WIFI

#define DHTPIN 0    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

 Serial.begin(115200);
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}

void loop() {
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();  
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);
  delay(200);
  Serial.print(t);
  Serial.println(h);
}
