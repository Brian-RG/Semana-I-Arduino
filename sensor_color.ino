#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define sensorOut 10
int frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // leyendo rojo 
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  //frecuencia rojo 
  frequency = pulseIn(sensorOut, LOW);
  //mapeando valores [0,255]
  frequency = map(frequency, 70,160,255,0);
  //imprimiendo valor
  if (frequency > 218){
    Serial.println("rojo");
  }
  //Serial.print("R= ");
  //Serial.print(frequency);
  //Serial.print("  ");
  delay(100);
  // leyendo verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // frecuancia verde
  frequency = pulseIn(sensorOut, LOW);
  //mapenado valores [0,255]
  frequency = map(frequency, 70,180,255,0);
  // imorimiendo valores
  if (frequency > 218){
    Serial.println("verde");
  }
  //Serial.print("G= ");
 //Serial.print(frequency);
  //Serial.print("  ");
  delay(100);
  // leyendo azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  //frecuencia azul
  frequency = pulseIn(sensorOut, LOW);
  //mapeando valores [0,255]
  frequency = map(frequency, 79,123,255,0);
  // imprimiendo valores
  if (frequency > 218){
    Serial.println("azul");
  }
  //Serial.print("B= ");
  //Serial.print(frequency);
  //Serial.println("  ");
  delay(100);
}
