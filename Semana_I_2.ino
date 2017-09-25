
void setup() {
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
    if(digitalRead(3)==LOW and digitalRead(4)==LOW){
      Serial.println("Estás presionando ambos botones");
      delay(1000);
    }
  else if(digitalRead(3)==LOW){
      Serial.println("Estás presionando el botón A");
      delay(1000);
    }
  else if(digitalRead(4)==LOW){
      Serial.println("Estás presionando el botón B");
      delay(1000);
    }

}
