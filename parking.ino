#include <Servo.h>
Servo myservo;   
int pos = 0;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(12, OUTPUT); 
  digitalWrite(12, LOW);
  myservo.attach(9); 
  Serial.begin(9600);
}

void loop() {
  // Measure distance in cm
  cm = 0.0343 * (readUltrasonicDistance(6, 7)/2);
  

  if (cm < 4.0) {
    Serial.print(cm);
    Serial.println(" cm");
  
    // Move servo from 0 to 120 degrees
    for (pos = 0; pos <= 120; pos += 1) { 
      myservo.write(pos);             
      delay(15);                       
    }
    delay(500);

    // Move servo from 120 back to 0 degrees
    for (pos = 120; pos >= 0; pos -= 1) { 
      myservo.write(pos);
      delay(15);                                     
    }
    delay(5000);
  }  

  delay(50); 
}