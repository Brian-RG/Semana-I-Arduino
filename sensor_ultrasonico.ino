long tiempo;
int disparador = 4;
int entrada = 5;
float distancia;

void setup() {
  Serial.begin(9600);
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
}

void loop() {
  digitalWrite(disparador, HIGH);
  delay (30);
  digitalWrite(disparador, LOW);

  tiempo = (pulseIn(entrada, HIGH)/2);

  distancia = float(tiempo * 0.0343);
  Serial.print(distancia);
  Serial.println("cm");
  
}
