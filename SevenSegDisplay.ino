
#include "SevenSegDisplay.h"

SevenSegDisplay::SevenSegDisplay(byte *in)
{
  pins = in;
  for (byte i = 0; i < 7; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

SevenSegDisplay::~SevenSegDisplay()
{
  SevenSegDisplay::off();
}

void SevenSegDisplay::off()
{
  for(byte i = 0; i < 7; i++)
    digitalWrite(pins[i], LOW);
}

void SevenSegDisplay::clear()
{
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], LOW);
  digitalWrite(pins[4], LOW);
  digitalWrite(pins[5], LOW);
  digitalWrite(pins[6], HIGH);
}

void SevenSegDisplay::writeNum(byte num)
{
  targetNum = num;
  switch(num)
  {
    case(0):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], HIGH);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], LOW);     
      break;
      
    case(1):
      digitalWrite(pins[0], LOW);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], LOW);
      digitalWrite(pins[6], LOW);
      break;
    
    case(2):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], LOW);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], HIGH);
      digitalWrite(pins[5], LOW);
      digitalWrite(pins[6], HIGH);     
      break;
      
    case(3):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], LOW);
      digitalWrite(pins[6], HIGH);     
      break;      
    
    case(4):
      digitalWrite(pins[0], LOW);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;      
    
    case(5):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], LOW);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;      
    
    case(6):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], LOW);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], HIGH);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;    
    
    case(7):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], LOW);
      digitalWrite(pins[6], LOW);     
      break;    
    
    case(8):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], HIGH);
      digitalWrite(pins[4], HIGH);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;    
    
    case(9):
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], LOW);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;
    
    default:
      digitalWrite(pins[0], LOW);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], HIGH);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], HIGH);
      digitalWrite(pins[5], HIGH);
      digitalWrite(pins[6], HIGH);     
      break;
  }
  currentNum = targetNum;
}
