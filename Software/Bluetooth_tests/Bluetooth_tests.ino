char data = 0;                //Variable for storing received data
void setup()
{
  Serial.begin(9600); 
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  
  Serial1.write("AT");
  
}
void loop()
{


  
  if (Serial.available() > 0){
    data = Serial.read();      //Read the incoming data and store it into variable data
    
    if (data!=10 & data!=13 ) {
      Serial1.write(data);
    }
    
    Serial.print(data);        //echo
    Serial.print("\n");        //New line
  }
    
    if (Serial1.available() > 0) // Send data only when you receive data:
  {
    data = Serial1.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line
  }

}
