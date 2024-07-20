#define BLYNK_TEMPLATE_ID "TMPL3g0dhCYKV"
#define BLYNK_TEMPLATE_NAME "RAIN ALERT"
#define BLYNK_AUTH_TOKEN "bYXkkpDyGQjhzvBECT56lram1sMFzCcs"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RAIN_SENSOR_PIN A0
#define RAIN_SENSOR_THRESHOLD 500 // adjust this value based on your sensor

char ssid[] = "Enter your hospot name";
char pass[] = "Enter your hospot password";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  int sensorValue = analogRead(RAIN_SENSOR_PIN);
  Serial.print("Rain sensor value: ");
  Serial.println(sensorValue);

  if (sensorValue < RAIN_SENSOR_THRESHOLD) {
    Blynk.logEvent("rainalert");
  }

  Blynk.virtualWrite(V0, sensorValue);

  Blynk.run();
  delay(1000);
}
