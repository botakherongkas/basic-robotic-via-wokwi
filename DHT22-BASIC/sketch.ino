#include <DHT.h>

#define DHTPIN 3 
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

int ledpin = 13;
int buzzerPin = 12; 

int melody[] = {262}; 

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 40.0 || temperature < 0 && (humidity < 40.0 || humidity > 60.0)) {
    digitalWrite(ledpin, HIGH);       
    tone(buzzerPin, melody[0], 500); 
    Serial.println("BAHAYA");
  } 
  else {
    digitalWrite(ledpin, LOW);        
    noTone(buzzerPin);                
  }
}
