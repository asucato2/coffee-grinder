#ifndef SABERTOOTH_H
#define SABERTOOTH_H

#include <Arduino.h>

class Sabertooth
{

  private:
    const long motorStepUpTime = 20; //milliseconds
    const long motorStepDownTime = 50;
    
    byte currentSpeed; //64 is off, 127 is full speed 
    byte targetSpeed;
    
    unsigned long previousMillis;  
    
  public:  
    void setSpeed(int speed);
    void stop();
    Sabertooth();
    ~Sabertooth(); 
};

#endif
