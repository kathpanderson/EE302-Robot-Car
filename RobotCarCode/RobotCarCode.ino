/*
Code to control the robot car.
*/

  // Set ports for motor outputs
  const int motorLeft = 9;
  const int motorRight = 10;

  // Drive number
  int drive = 51;

    // Set ports for photoresistor sensor input
  const int leftColorPort = 1;
  const int rightColorPort = 0;
  const int middleColorPort = 2;
  
  // Set ports for IR sensor input
  const int leftIRPort = 3;
  const int rightIRPort = 5;
  const int middleIRPort = 4;

    // Initialize run duration for motors, as well as white/black voltage cut off
  // and distance to stop at
  int duration = 100; // Update after testing
  int turnDuration = 250;
  int BlacktoWhite = 155; //White < 3V, black > 3V
  int redToWhite = 200; // White is < 1.5V, red > 1.5V
  int stopDistance = 266; // if greater than theres a thing so stop

  int rightColorVal = 0;
  int leftColorVal = 0;
  int middleColorVal = 0;
  int middleDistance = 0;
  int leftDistance = 0;
  int rightDistance = 0;

void setup() {

  // Set ports for enable output (if needed)
  // const int enableOutput = 

    Serial.begin(9600);
    pinMode(motorLeft, OUTPUT);
    pinMode(motorRight, OUTPUT);
   
    // write with digital
    // read will be analog
}

void loop() {


  // Initilize both motors to low. Motors will always default to low, unless turned on by some part of the program.
  // Once a motor is turned on, it MUST be turned off when the loop breaks.
  analogWrite(motorRight, 0);
  analogWrite(motorLeft, 0);

  middleDistance = analogRead(middleIRPort);

  //  SWITCH TO LOW BEFORE YOU RUN ACTUAL CODE, HIGH ONLY FOR TESTING!!!!!!!!!!!!!!
    
  // Loop 1: Follow the sensors on lines. Break upon distance from wall. 
  
  while(middleDistance < stopDistance){

     rightColorVal = analogRead(rightColorPort);
     leftColorVal = analogRead(leftColorPort);
     middleColorVal = analogRead(middleColorPort);
    
    // Subloop 1: Both sensors see white. On this, continue forward for duration.
    
    if((rightColorVal <= BlacktoWhite and leftColorVal <= BlacktoWhite)){
      
      // Write HIGH output to both motors
      analogWrite(motorRight, drive);
      analogWrite(motorLeft, drive);

      delay(duration);
  
      analogWrite(motorRight, 0);
      analogWrite(motorLeft, 0);

      delay(duration);

      rightColorVal = analogRead(rightColorPort);
      leftColorVal = analogRead(leftColorPort);
      middleColorVal = analogRead(middleColorPort);

      int i = 0;

      while(i < 6 and rightColorVal <= BlacktoWhite and leftColorVal <= BlacktoWhite and middleColorVal <= BlacktoWhite){
        analogWrite(motorRight, drive);
        analogWrite(motorLeft, drive);
  
        delay(duration);
    
        analogWrite(motorRight, 0);
        analogWrite(motorLeft, 0);
  
        delay(duration);
  
        rightColorVal = analogRead(rightColorPort);
        leftColorVal = analogRead(leftColorPort);
        middleColorVal = analogRead(middleColorPort);

        i = i + 1;
        
      }

      if( i == 6 ){
        while(leftColorVal <= BlacktoWhite){
          analogWrite(motorRight, drive);
          delay(turnDuration);
  
          analogWrite(motorRight, 0);
          
          delay(duration);
          leftColorVal = analogRead(leftColorPort);
        }
      }
            
    }

   else if(rightColorVal >= BlacktoWhite and leftColorVal >= BlacktoWhite){
      
      // Write HIGH output to both motors
      analogWrite(motorRight, drive);
      analogWrite(motorLeft, drive);

      delay(duration);
  
      analogWrite(motorRight, 0);
      analogWrite(motorLeft, 0);

      delay(duration);

      rightColorVal = analogRead(rightColorPort);
      leftColorVal = analogRead(leftColorPort);
      middleColorVal = analogRead(middleColorPort);
    }

   // If condiiton met to break loop, turn off both motors
    
    // Subloop 2: Left sensor sees black. Right sensor sees white.
    else if(rightColorVal <= BlacktoWhite and leftColorVal > BlacktoWhite){
        
        analogWrite(motorRight, drive);

        delay(turnDuration);

        analogWrite(motorRight, 0);
        analogWrite(motorLeft, 0);

        delay(duration);

        rightColorVal = analogRead(rightColorPort);
        leftColorVal = analogRead(leftColorPort);
        middleColorVal = analogRead(middleColorPort);
    }

      // If condition met to exit loop, turn off right motor.
      
    // Subloop 3: Left sensor sees white. Right sensor sees black.
    else if(leftColorVal <= BlacktoWhite and rightColorVal > BlacktoWhite){
       
        analogWrite(motorLeft, drive);

        delay(turnDuration);

        analogWrite(motorRight, 0);
        analogWrite(motorLeft, 0);

        delay(duration);
    }

    middleDistance = analogRead(middleIRPort);

  }
  
  
  while(analogRead(middleIRPort) > stopDistance){
  // Loop 2: Delay until wall removed
    delay(duration);
  }

 // while(analogRead(middleColorPort) > BlacktoWhite or analogRead(rightColorPort) > BlacktoWhite or analogRead(leftColorPort) > BlacktoWhite){
 //   analogWrite(motorLeft, drive);
 //   analogWrite(motorRight, drive);
 //   delay(duration);

 //   analogWrite(motorLeft, 0);
 //   analogWrite(motorRight, 0);
 //  }

 // analogWrite(motorLeft, 0);
 // analogWrite(motorRight, 0);
  
  while(analogRead(middleColorPort) < redToWhite){
  // Loop 3: Upon wall being removed, move forwards using distance sensors as guideance.
  // Stop when sensor finds line.

   rightDistance = analogRead(rightIRPort);
   leftDistance = analogRead(leftIRPort);
  
    // If voltage right is less than voltage left, turn left.
    if (rightDistance > leftDistance){
      analogWrite(motorRight, drive);
      
      delay(duration);
    }
    
    // If volatage left is less than voltage left, turn right.
    else if (rightDistance < leftDistance){
      analogWrite(motorLeft, drive);
      
      delay(duration);
    }
    
    // If voltages equal, move forwards.
    else{
      analogWrite(motorLeft, drive);
      analogWrite(motorRight, drive);
      delay(duration);
    }

    analogWrite(motorLeft, 0);
    analogWrite(motorRight, 0);
    
  }

  analogWrite(motorLeft, 0);
  analogWrite(motorRight, 0);
}
