int Sensor=2;
int lectura;
int luz;
void setup() {
  // put your setup code here, to run once:
  pinMode(Sensor,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura=analogRead(Sensor);
  luz = map (lectura,450 ,910 ,0 ,100);
  Serial.println(luz);
  delay(100);
}

