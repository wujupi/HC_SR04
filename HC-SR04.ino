#include "HC_SR04.h"

#define ECHO_PIN A3
#define TRIG_PIN 11

HC_SR04 hc_sr04;

void setup()
{
  Serial.begin(9600);
  hc_sr04.init(ECHO_PIN, TRIG_PIN);
}

void loop()
{
  hc_sr04.getDistance();
  Serial.println(hc_sr04.distance);
  delay(1000);
}
