//Ultrasonic sensor code is built on assumption we are using the PING))) ultrasonic rangefinder.
const int RANGEPIN = 7;
void setup(){
  Serial.begin(9600);
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
