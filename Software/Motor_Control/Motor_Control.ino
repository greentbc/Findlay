


//#include "Bluetooth.h"
#include "Motor.h"

HardwareSerial & BT = Serial1; // BT  for Bluetooth is clearer than Serial1

//Now with basic movemnts!



Motor myMo;

void setup() {



  

}

void loop() {
//test of motors
  delay(2000);
  myMo.lMotor(150, true); 
  myMo.rMotor(150, true); 
  delay(2000); 
  myMo.lMotor(0, false); 
  myMo.rMotor(0, false);  
  delay(2000);
  myMo.lMotor(150, false); 
  myMo.rMotor(150, false); 
  delay(2000);
  myMo.lMotor(255, true); 
  myMo.rMotor(255, false); 
  delay(2000);
}
