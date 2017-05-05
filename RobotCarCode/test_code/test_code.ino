  int drive = 5;
  int pause = 0;

  int motor1 = 9;
  int motor2 = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(motor1, 51);
  analogWrite(motor2, 51);

  delay(500);

  analogWrite(motor1, 0);

  delay(500);

  analogWrite(motor2, 0);

  delay(1000);
  
}
