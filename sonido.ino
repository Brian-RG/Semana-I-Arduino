int out = A4;
int led1 = 2;
int led2 = 4;
int sensorv = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorv = analogRead(out);
  Serial.println(sensorv);
  if( sensorv < 100) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(100);
  }
  else if(sensorv > 100) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    delay(100);
  }
}
