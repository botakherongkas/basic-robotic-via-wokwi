#define trigpin 13 
#define echopin 12
#include <Servo.h>

Servo myservo;
int led = 10;
int buzzer = 11;

int melody[] = {262,294};

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  myservo.attach(9);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  long duration = pulseIn(echopin, HIGH);
  float distance = duration * 0.03421 / 2;

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 300) { 
    myservo.write(180);         
    digitalWrite(led, HIGH);   
    tone(buzzer, melody[0]);   
  } 
  else { 
    myservo.write(0);          
    digitalWrite(led, LOW);    
    noTone(buzzer);            
  }

  delay(150); 
}
