/*
Code to control the robot car.
*/

void setup() {
  
  // Set ports for motor outputs
  const int motorLeft = ;
  const int motorRight = ;
  
  // Set ports for photoresistor sensor input
  const int leftColorPort = ;
  const int rightColorPort = ;
  const int middleColorPort = ;
  
  // Set ports for IR sensor input
  const int leftIRPort = ;
  const int rightIRPort = ;
  const int middleIRPort = ;
  
  // Intilize values read from IR sensors
  int leftIRVal = 0;
  int rightIRVal = 0;
  int middleIRVal = 0;
  
  // Initialize run duration for motors, as well as white/black voltage cut off
  // and distance to stop at
  int duration = 0; // Update after testing
  int BlacktoWhite = 3; //White < 3V, black > 3V
  int stopDistance = 0; // Update after testing
  
    
    // write with digital
    // read will be analog
}

void loop() {

  // Initilize both motors to low. Motors will always default to low, unless turned on by some part of the program.
  // Once a motor is turned on, it MUST be turned off when the loop breaks.
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
    
  // Loop 1: Follow the sensors on lines. Break upon distance from wall. 
  
  while(analogRead(middleIRPort) < stopDistance){
    
    // Subloop 1: Both sensors see white. On this, continue forward for duration.
    while(analogRead(rightColorPort) < BlacktoWhite and analogRead(leftColorPort) < BlacktoWhite){
      
      // Write HIGH output to both motors
      digitalWrite(motorRight, HIGH);
      digitalWrite(motorLeft, HIGH);
      
      // Wait with motors on.
      delay(duration);
    }

   // If condiiton met to break loop, turn off both motors
    digitalWrite(motorRight, LOW);
    digitalWrite(motorLeft, LOW);
    
    // Subloop 2: Left sensor sees black. Right sensor sees white.
    while(analogRead(rightColorPort < BlacktoWhite) and analogRead(leftColorPort > BlacktoWhite)){
      
      // Condition 1: Middle sensor sees white. This is normal left turn.
      while(analogRead(middleColorPort) < BlacktoWhite):
        
        digitalWrite(motorRight, HIGH);
        
        delay(duration);
    }

      // If condition to exit loop met, turn off right motor
      digitalWrite(motorRight, LOW);
        
      // Condition 2: Middle sensor sees black. This is the right angle turn condition!
        // Left side off. Right side on. For duration. 
      while(analogRead(middleColorPort) > BlacktoWhite){

        digitalWrite(motorRight, HIGH);

        delay(duration);
      }

      // If condition met to exit loop, turn off right motor.
      digitalWrite(motorRight, LOW);
      
    // Subloop 3: Left sensor sees white. Right sensor sees black.
    while(analogRead(leftColorPort < BlacktoWhite) and analogRead(rightColorPort > BlacktoWhite){
      
      // Condition 1: Middle sensor sees white. This is normal right turn.
      while(analogRead(middleColorPort < BlacktoWhite){
        digitalWrite(motorLeft, HIGH);
        delay(duration);
      }
      digitalWrite(motorLeft, LOW);
      
      // Condition 2: Middle sensor sees black. This is right angle turn to right condition!
      while(analogRead(middleColorPort > BlacktoWhite){
        digitalWrite(motorLeft, HIGH);
        delay(duration);
      }
      digitalWrite(motorLeft, LOW);
    }
  }
  
  while(analogRead(middleIRPort) > stopDistance){
  // Loop 2: Delay until wall removed
    delay(duration)
  }
  
  while(){
  // Loop 3: Upon wall being removed, move forwards using distance sensors as guideance.
  // Stop when sensor finds line.
    // If voltage right is less than voltage left, turn left.
    // If volatage left is less than voltage left, turn right.
    // If voltages equal, move forwards.
  }
}
