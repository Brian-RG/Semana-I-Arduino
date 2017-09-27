#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long tiempo;
int disparador = 30;
int entrada = 34;
float distancia;
int enable = 13;
int fotores  = 9;
int lectura;
int luz;

dht DHT;

#define DHT11_PIN 7

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  pinMode(enable,INPUT_PULLUP);
  pinMode(fotores,INPUT);
}

void loop()
{
 if (digitalRead(enable) == LOW){
  lcd.clear();
  delay(1000);
  digitalWrite(disparador, HIGH);
  delay (30);
  digitalWrite(disparador, LOW);

  tiempo = (pulseIn(entrada, HIGH)/2);

  distancia = float(tiempo * 0.0343);

  lcd.setCursor(0,0);//(columna,fila)
  lcd.print(distancia);//imprime la distacnia en cm en el lcd
  lcd.setCursor(8,0);
  lcd.print("cm");

  lectura = analogRead (fotores);
  Serial.println (lectura);
  luz = map (lectura,790,810,100,0);
  lcd.setCursor(0,1);
  lcd.print(luz);
  lcd.print(" %");
  delay(4000);
  
  lcd.clear();
  
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  
  }
 }


