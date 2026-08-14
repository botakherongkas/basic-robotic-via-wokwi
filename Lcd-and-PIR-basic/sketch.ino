#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pirpin = 2;
int ledpin = 13;
int buzzer = 11;
int servopin = 3;
int melody[] = {
  659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 392, 0,};
int lastStatus = -1; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
pinMode(pirpin, INPUT);     
pinMode(buzzer, OUTPUT);    
myservo.attach(servopin);
lcd.init();
lcd.clear();
lcd.backlight();

 lcd.setCursor(0, 0);
  lcd.print("Hello world");
  delay(2000);
  lcd.clear();
}

void loop() { 
  int pirvalue = digitalRead(pirpin); 
  Serial.print("Value: "); 
  Serial.println(pirvalue); 
  
  if (pirvalue == 1) { 
    Serial.println("Motion Detected!"); 
    digitalWrite(ledpin, HIGH); 
    myservo.write(90); 
    tone(buzzer, melody[0]); 
    
    if (lastStatus != 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("MOTION DETECTED!");
      lcd.setCursor(0, 1);
      lcd.print("GATE CLOSING");
      lastStatus = 1;
    }
    delay(200); 
  } 
  else { 
    myservo.write(0); 
    digitalWrite(ledpin, LOW); 
    noTone(buzzer); 
    
    if (lastStatus != 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Status: Secure");
      lcd.setCursor(0, 1);
      lcd.print("Scanning...");
      lastStatus = 0;
    }
    delay(200);
  } 
}

