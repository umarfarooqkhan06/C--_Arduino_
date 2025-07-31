#include <ESP8266WiFi.h>
#include <FirebaseRealtime.h>
#include "DHT.h"

// Replace with your WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

// Replace with your Firebase Realtime Database info
#define FIREBASE_REALTIME_URL "YOUR_FIREBASE_URL"
#define FIREBASE_REALTIME_SECRET "YOUR_DATABASE_SECRET"

#define DHTPIN 2
#define DHTTYPE DHT11

FirebaseRealtime firebase;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  firebase.begin(FIREBASE_REALTIME_URL, FIREBASE_REALTIME_SECRET, ssid, pass);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  DynamicJsonDocument doc(256);
  doc["humidity"] = h;
  doc["temperature"] = t;
  String jsonData;
  serializeJson(doc, jsonData);

  int response = firebase.save("sensors", "dht11", jsonData);
  Serial.println("Firebase response: " + String(response));

  doc.clear();
  delay(5000);
}
