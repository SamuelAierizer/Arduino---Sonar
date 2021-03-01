#include <Servo.h> 

const int trigPin = 6;
const int echoPin = 7;

long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(8); // 
}

void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
    myServo.write(i);
    delay(30);
    
    distance = calculateDistance();
  
    Serial.print(i); // degree
    Serial.print(","); // 
    Serial.print(distance); //distance
    Serial.print("."); 
  }
  
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
    myServo.write(i);
    delay(30);
    
    distance = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); 
  distance = duration*0.034/2;
  return distance;
}
