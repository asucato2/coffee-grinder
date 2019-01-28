/*
Created 11/18/18 by Andrew Sucato
*/
#include "Sabertooth.h"

Sabertooth::Sabertooth()
{
  Serial.begin(9600);
  currentSpeed = 64;
  targetSpeed = 64;
  setSpeed(targetSpeed);
  previousMillis = 0;
}

Sabertooth::~Sabertooth()
{
  Sabertooth::stop();
}

void Sabertooth::setSpeed(int speed)
{
  targetSpeed = speed;
  
  Serial.write(currentSpeed);
  unsigned long currentMillis = millis();
  previousMillis = currentMillis;
  
  while(currentSpeed != targetSpeed)
  {
    currentMillis = millis();
    
    if ((targetSpeed > currentSpeed) && (currentMillis - previousMillis >= motorStepUpTime))
    {    
      currentSpeed++;
      Serial.write(currentSpeed);
      previousMillis = currentMillis;
    }
    else if ((targetSpeed < currentSpeed) && (currentMillis - previousMillis >= motorStepDownTime))
    {
      currentSpeed--;
      Serial.write(currentSpeed);
      previousMillis = currentMillis;
    }
  }
}

void Sabertooth::stop()
{
  Sabertooth::setSpeed(64);
}
