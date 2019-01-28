/*

*/
#include "Sabertooth.h"
#include "SevenSegDisplay.h"
#include "PushButton.h"

const byte grindTime = 60;

const byte disp1Pins[8] = {3, 4, 5, 6, 7, 8, 9};
const byte disp2Pins[8] = {10, 11, 12, 13, A0, A1, A2};
const byte pb1Pin = 2;

Sabertooth motor;
SevenSegDisplay disp1(disp1Pins);
SevenSegDisplay disp2(disp2Pins);
PushButton pb1(pb1Pin);

enum grinderStates {OFF, 
                    RUNNING};
enum grinderStates state;

void offState();
void runningState();
void updateDisplays();

void setup() {
  Serial.begin(9600);
  state = OFF;
}

void loop() 
{
  switch(state)
  {
    case(OFF):
      offState();
      break;
      
    case(RUNNING):
      runningState();
      break;
  }
}

void offState()
{
  delay(10);
  motor.stop();
  disp1.clear();
  disp2.clear();
  if(pb1.isPressed())
  {
    state = RUNNING;
    delay(50); 
  }
}

void runningState()
{
  delay(10);
  int timeLeft = grindTime;
  updateDisplay(timeLeft);
  
  motor.setSpeed(127);

  unsigned long currentMillis = millis();
  unsigned long previousMillis = currentMillis;

  while((timeLeft >= 0) && (!pb1.isPressed()))
  {
    currentMillis = millis();
    if (currentMillis - previousMillis >= 1000)
    {
      timeLeft--;
      updateDisplay(timeLeft);
      previousMillis = currentMillis;
    }
  }

  state = OFF;
  
  
}

void updateDisplay(int number)
{
  disp1.writeNum(number / 10);
  disp2.writeNum(number % 10);
}
