#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Arduino.h>

class PushButton
{
  private:
    byte pin;
    bool value;
    
  public:
    PushButton(byte in);
    ~PushButton();
    bool getValue();
    bool isPressed();
  
};

#endif
