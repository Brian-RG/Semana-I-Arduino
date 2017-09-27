#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int x = 10;
long tiempo;
int disparador = 30;
int entrada = 34;
float distancia;

void setup() {
  Serial.begin(9600);
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  
  digitalWrite(disparador, HIGH);
  delay (30);
  digitalWrite(disparador, LOW);

  tiempo = (pulseIn(entrada, HIGH)/2);

  distancia = float(tiempo * 0.0343);
  
  lcd.setCursor(0,0);//(columna,fila)
  lcd.print(distancia);//imprime la distacnia en cm en el lcd
  lcd.setCursor(8,0);
  lcd.print("cm");
}
