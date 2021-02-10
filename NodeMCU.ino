#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run
#define FIREBASE_HOST "PROJECT_NAME.firebaseio.com"     
#define FIREBASE_AUTH "SECRET_KEY"
#define WIFI_SSID "WIFI_NAME"
#define WIFI_PASSWORD "WIFI_PASS"

const int ledPin =  13;				//for D7 pin of NodeMCU

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting...");
  }

  Serial.println("Connected...");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  String status=Firebase.getString("LED/status");
  if(status=="On"){
    Serial.println("high");  
    digitalWrite(ledPin, HIGH);
  }
  if(status=="Off"){
    Serial.println("low");  
    digitalWrite(ledPin, LOW);
  }
}
