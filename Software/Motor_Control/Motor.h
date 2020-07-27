#ifndef Motor_h
#define Motor_h

#include "Arduino.h"







class Motor{
// Right Motor connections
static const int rMoEn = 7;   //green wire //enable right motor
static const int rMoIn3 = 9;  //orange 
static const int rMoIn4 = 8;  //yellow
// Left Motor connections
static const int lMoEn = 4;   //gray wire //enable left motor
static const int lMoIn1 = 5;  //purple wire
static const int lMoIn2 = 6;  //blue wire
  
  
  
  public:
    Motor();
    void rMotor(byte speed, bool direction);//should be between 0-255 True is forward, False is Backward
    void lMotor(byte speed, bool direction);//should be between 0-255 True is forward, False is Backward
    
  private:



};


#endif /* Motor_h */
