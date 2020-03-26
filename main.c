#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "arduino-****.firebaseio.com"
#define FIREBASE_AUTH "kkVlgstBKo3lRhpSdhZILZG0fZUJlIr********"
#define WIFI_SSID "AUGIE_CAEMS"
#define WIFI_PASSWORD "AugieCaems123"
#define LED D2

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

    if (Firebase.getString("LED_STATUS") == "ON") {
        digitalWrite(LED, HIGH);
    }
    else if (Firebase.getString("LED_STATUS") == "OFF") {
        digitalWrite(LED, LOW);
    }

    delay(2000);
}