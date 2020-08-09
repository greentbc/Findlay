#include "Motor.h"


Motor::Motor(){
  
  // Set all the motor control pins to outputs
  pinMode(rMoEn, OUTPUT);
  pinMode(lMoEn, OUTPUT);
  pinMode(lMoIn1, OUTPUT);
  pinMode(lMoIn2, OUTPUT);
  pinMode(rMoIn3, OUTPUT);
  pinMode(rMoIn4, OUTPUT);

  
  // Turn off motors - Initial state
  digitalWrite(lMoIn1, LOW);
  digitalWrite(lMoIn2, LOW);
  digitalWrite(rMoIn3, LOW);
  digitalWrite(rMoIn4, LOW);
}


//should be between 0-255 True is forward, False is Backward
void Motor::lMotor(byte speed, bool direction){

  if ((speed < 0) || (speed > 255)){
    //OUTSIDE OF SPEED RANGE
    return;
}

  if (speed == 0){
    digitalWrite(lMoIn1, LOW);
    digitalWrite(lMoIn2, LOW);
    return;
  }

  if (direction == false){
    digitalWrite(lMoIn1, LOW);
    digitalWrite(lMoIn2, HIGH);
    analogWrite(lMoEn, speed);
    return;
  }
  if (direction == true){ 
    digitalWrite(lMoIn1, HIGH);
    digitalWrite(lMoIn2, LOW);
    analogWrite(lMoEn, speed);
    return;
  }
}


//should be between 0-255 True is forward, False is Backward
void Motor::rMotor(byte speed, bool direction){

if ((speed < 0) || (speed > 255)){
  //OUTSIDE OF SPEED RANGE
  return;
}

  if (speed == 0){
      digitalWrite(rMoIn3, LOW);
      digitalWrite(rMoIn4, LOW);
      return;
  }

  if (direction == true){
    digitalWrite(rMoIn3, LOW);
    digitalWrite(rMoIn4, HIGH);
    analogWrite(rMoEn, speed);
    return;
  }
  if (direction == false){ 
    digitalWrite(rMoIn3, HIGH);
    digitalWrite(rMoIn4, LOW);
    analogWrite(rMoEn, speed);
    return;
  }
}


void Motor::testMotor(){
  delay(2000);
  lMotor(150, true); 
  rMotor(150, true); 
  delay(2000); 
  lMotor(0, false); 
  rMotor(0, false);  
  delay(2000);
  lMotor(150, false); 
  rMotor(150, false); 
  delay(2000);
  lMotor(255, true); 
  rMotor(255, false); 
  delay(2000);
  lMotor(0, false); 
  rMotor(0, false);  
}
