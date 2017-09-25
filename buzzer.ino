int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  beep(400); //Beep
  delay(1000);

}

void loop() {
  beep(50);
  delay(500);
}

void beep(unsigned char delayms) { 
  analogWrite(buzzerPin, 20);
  delay(delayms);
  analogWrite(buzzerPin ,0);
  delay(delayms);
  
}
