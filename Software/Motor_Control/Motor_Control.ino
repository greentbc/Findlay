


//#include "Bluetooth.h"
#include "Motor.h"




HardwareSerial & BT = Serial1; // BT  for Bluetooth is clearer than Serial1



Motor myMo;

void setup() {

 Serial.begin(9600); 
  BT.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  
  BT.write("AT");

  

}

//called when there is avaliable data from Bluetooth
void serialEvent1(){
  char data = 0;                //Variable for storing received data
  while (BT.available() > 0){
    data = BT.read();

    /*Do something with the data. This might get all re-done. It seemed easy to work with for now
    right now it works like this:
    Left      Right
    Q=100%    E=100%
    A=80%     D=80%
    Z=60%     C=60%
    z=-60%    c=-60%
    a=-80%    d=-80%
    q=-100%   e=-100%
    1=0%      3=0%
    */

  switch (data){
    
    case '1':
      myMo.lMotor(0, true);
      break;
    case '3':
      myMo.rMotor(0, true);
      break;
    
    case 'Q':
      myMo.lMotor(255, true);
      break;
    case 'A':
      myMo.lMotor(200, true);
      break;  
    case 'Z':
      myMo.lMotor(150, true);
      break;  
  
    case 'q':
      myMo.lMotor(255, false);
      break;
    case 'a':
      myMo.lMotor(200, false);
      break;  
    case 'z':
      myMo.lMotor(150, false);
      break;  

    case 'E':
      myMo.rMotor(255, true);
      break;
    case 'D':
      myMo.rMotor(200, true);
      break;  
    case 'C':
      myMo.rMotor(150, true);
      break;  
  
    case 'e':
      myMo.rMotor(255, false);
      break;
    case 'd':
      myMo.rMotor(200, false);
      break;  
    case 'c':
      myMo.rMotor(150, false);
      break;           
    
  }//end of switch
    
  }//end of while
}//end of serialEvent1()


void loop() {
//        myMo.testMotor();
}
