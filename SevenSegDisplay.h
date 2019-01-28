#ifndef SEVENSEGDISPLAY_H
#define SEVENSEGDISPLAY_H

#include <Arduino.h>

class SevenSegDisplay
{
  private:
    byte *pins;
    byte currentNum;
    byte targetNum;

  public:
    SevenSegDisplay(byte *in);
    ~SevenSegDisplay();
    void writeNum(byte num);
    void off();
    void clear();
};

#endif
