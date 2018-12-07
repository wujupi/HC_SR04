#include "HC_SR04.h"
#include "Ticker.h"
#include "PinChangeInt.h"

Ticker ticker;

HC_SR04::HC_SR04() {}
HC_SR04::~HC_SR04() {}

void HC_SR04::measureDistance()
{
  if (flag == 0)
  {
    time = micros();
    attachPinChangeInterrupt(echo_pin, measureDistance, FALLING);
    flag = 1;
  }
  else if (flag == 1)
  {
    distance = (micros() - time) * 0.017;
    flag = 2;
  }
}

void HC_SR04::getDistance()
{
  flag = 0;
  attachPinChangeInterrupt(echo_pin, measureDistance, RISING);
  digitalWrite(echo_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
}

void HC_SR04::init(int echo_pin, int trig_pin)
{
  this->echo_pin = echo_pin;
  this->trig_pin = trig_pin;
  ticker.start(getDistance, 50);
}