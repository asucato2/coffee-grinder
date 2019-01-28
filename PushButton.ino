#include "PushButton.h"

PushButton::PushButton(byte in)
{
  pin = in;
  pinMode(pin, INPUT);
}

PushButton::~PushButton()
{
  
}

bool PushButton::getValue()
{
  value = digitalRead(pin);
  return value;
}

bool PushButton::isPressed()
{
  value = PushButton::getValue();
  return value;
}
