int ldrpin = A0; 
int led = 13; 

const float GAMMA = 0.7; 
const float RL10 = 50; 

void setup() { 
  pinMode(led, OUTPUT); 
  Serial.begin(9600); 

  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
} 

void loop() { 
  int ldrvalue = analogRead(ldrpin); 
  
  float voltage = (float)ldrvalue * 5.0 / 1023.0; 
  if (voltage >= 4.99) {
    voltage = 4.99;
  }
  
  float resistance = 10000.0 * voltage / (5.0 - voltage); 
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1.0 / GAMMA)); 

  Serial.print("Analog: "); 
  Serial.print(ldrvalue); 
  Serial.print(" | Lux: "); 
  Serial.println(lux); 

  if (lux <= 450.0) { 
    digitalWrite(led, HIGH); 
  } else { 
    digitalWrite(led, LOW); 
  } 
  
  delay(100); 
}
