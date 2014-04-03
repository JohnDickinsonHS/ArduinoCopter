#include <Wire.h>
#include <Adafruit_MotorShield.h>
//Ultrasonic sensor code is built on assumption we are using the PING))) ultrasonic rangefinder.
const int RANGEPIN = 7;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *cwOne = AFMS.getMotor(1);
Adafruit_DCMotor *cwTwo = AFMS.getMotor(2);
Adafruit_DCMotor *ccwOne = AFMS.getMotor(3);
Adafruit_DCMotor *ccwTwo = AFMS.getMotor(4);

void setup(){
  Serial.begin(9600);
  AFMS.begin();
  //set directions of and enable motors
  cwOne->setSpeed(0);
  cwOne->run(FORWARD);
  cwOne->run(RELEASE);
  cwTwo->setSpeed(0);
  cwTwo->run(FORWARD);
  cwTwo->run(RELEASE);
  ccwOne->setSpeed(0);
  ccwOne->run(FORWARD);
  ccwOne->run(RELEASE);
  ccwTwo->setSpeed(0);
  ccwTwo->run(FORWARD);
  ccwTwo->run(RELEASE);
}

void loop(){
  //Reset rangefinder every time the loop runs
  long duration, inches, cm;
  pinMode(RANGEPIN, OUTPUT);
  digitalWrite(RANGEPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(RANGEPIN, HIGH);
  delayMicroseconds(5);
  //Switch to input, read duration of ultrasonic response time
  pinMode(RANGEPIN, INPUT);
  duration = pulseIn(RANGEPIN, HIGH);
  //convert time to distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  //motor control
  //TODO: SPEED RELATIONS WHEN TESTABLE
  cwOne->setSpeed(255-cm);
  cwTwo->setSpeed(255-cm);
  ccwOne->setSpeed(255-cm);
  ccwTwo->setSpeed(255-cm);
  
  //Output over serial for debug
  /*Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();*/
  
  delay(100);
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
