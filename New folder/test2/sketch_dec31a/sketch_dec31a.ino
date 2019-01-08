#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define Relay_1 5
#define Relay_2 4
#define Relay_3 0
#define Relay_4 2
// Set these to run example.
#define FIREBASE_HOST “relay-seppy.firebaseio.com”
#define FIREBASE_AUTH “”
#define WIFI_SSID “Viet Dung”
#define WIFI_PASSWORD “3vdung64”
int state_1 = 1;
int state_2 = 1;
int state_3 = 1;
int state_4 = 1;
int state_5 = 1;
int state_6 = 1;
int state_7 = 1;
int state_8 = 1;
void setup() {
 Serial.begin(115200);
pinMode(Relay_1, OUTPUT);
 pinMode(Relay_2, OUTPUT);
 pinMode(Relay_3, OUTPUT);
 pinMode(Relay_4, OUTPUT);
digitalWrite(Relay_1, state_1);
 digitalWrite(Relay_2, state_2);
 digitalWrite(Relay_3, state_3);
 digitalWrite(Relay_4, state_4);
// digitalWrite(Relay_5, state_5);
// digitalWrite(Relay_6, state_6);
// digitalWrite(Relay_7, state_7);
// digitalWrite(Relay_8, state_8);
// connect to wifi.
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print(“connecting”);
 while (WiFi.status() != WL_CONNECTED) {
 Serial.print(“.”);
 delay(500);
 }
 Serial.println();
 Serial.print(“connected: “);
 Serial.println(WiFi.localIP());
 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
int n = 0;
void loop() {
 state_1 =Firebase.getInt(“Relay_1”);
 state_2 =Firebase.getInt(“Relay_2”);
 state_3 =Firebase.getInt(“Relay_3”);
 state_4 =Firebase.getInt(“Relay_4”);
// state_5 =Firebase.getInt(“Relay_5”);
// state_6 =Firebase.getInt(“Relay_6”);
// state_7 =Firebase.getInt(“Relay_7”);
// state_8 =Firebase.getInt(“Relay_8”);
// get value 
// Serial.print(“Relay_1: “);
 Serial.println(state_1);
 digitalWrite(Relay_1, !state_1);
 
 // get value 
// Serial.print(“Relay_2: “);
 Serial.println(state_2);
 digitalWrite(Relay_2, !state_2);
 
 // get value 
// Serial.print(“Relay_3: “);
 Serial.println(state_3);
 digitalWrite(Relay_3, !state_3);
 
 // get value 
// Serial.print(“Relay_4: “);
 Serial.println(state_4);
 digitalWrite(Relay_4, !state_4);
 
// // get value 
// Serial.print(“Relay_5: “);
// Serial.println(state_5);
// digitalWrite(Relay_5, state_5);
// 
// // get value 
// Serial.print(“Relay_6: “);
// Serial.println(state_6);
// digitalWrite(Relay_6, state_6);
// // get value 
// Serial.print(“Relay_7: “);
// Serial.println(state_7);
// digitalWrite(Relay_7, state_7);
// 
// // get value 
// Serial.print(“Relay_8: “);
// Serial.println(state_8);
// digitalWrite(Relay_8, state_8);
 //Serial.println(“________________________”);
 delay(100);
}
