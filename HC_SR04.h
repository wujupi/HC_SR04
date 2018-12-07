#ifndef HC_SR04_H
#define HC_SR04_H

class HC_SR04
{
public:
  HC_SR04();
  ~HC_SR04();
  double distance;
  void init(int echo_pin, int trig_pin);
  void getDistance();

private:
  int echo_pin;
  int trig_pin;
  int flag = 0;
  unsigned long time = 0;
  void measureDistance();
};

#endif
