#include <LiquidCrystal.h>
#include <Servo.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int x = 10;
long tiempo;
int disparador = 30;
int entrada = 34;
float distancia;
Servo servoMotor;
int enable = 13;
int buzz = 22;

void setup() {
  Serial.begin(9600);
  pinMode(disparador,OUTPUT);
  pinMode(entrada,INPUT);
  pinMode(buzz,OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  servoMotor.attach(9);
  servoMotor.write(0);
  pinMode(enable,INPUT_PULLUP);
}

void loop() {
  analogWrite(buzz,0);
 if( digitalRead(enable) == LOW){
  lcd.clear();
  
  
  digitalWrite(disparador, HIGH);
  delay (30);
  digitalWrite(disparador, LOW);

  tiempo = (pulseIn(entrada, HIGH)/2);

  distancia = float(tiempo * 0.0343);

  if(distancia < 10){
    lcd.print("objeto demasiado");
    lcd.setCursor(5,1);
    lcd.print("cerca");
    digitalWrite(buzz, HIGH);
    delay(2000);
  }
  
   if (distancia > 200){
  for (int i = 0; i <= 180; i++)
    {
     // Desplazamos al ángulo correspondiente
     servoMotor.write(i);
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print(" grados lejos");
      lcd.setCursor(0,0);//(columna,fila)
      lcd.print(distancia);//imprime la distacnia en cm en el lcd
      lcd.setCursor(8,0);
      lcd.print("cm");
      delay(125);

    }
  }
  if (distancia > 100 and distancia < 200){
  for (int i = 0 ; i <= 180; i++)
    {
     // Desplazamos al ángulo correspondiente
     servoMotor.write(i);
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print(" grados medio");
      lcd.setCursor(0,0);//(columna,fila)
      lcd.print(distancia);//imprime la distacnia en cm en el lcd
      lcd.setCursor(8,0);
      lcd.print("cm");
      delay(175);
     
      
    }
  }
  if (distancia < 100 and distancia > 10){
  for (int i = 0; i <= 180; i++)
    {
     // Desplazamos al ángulo correspondiente
     servoMotor.write(i);
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print(" grados cerca");
      lcd.setCursor(0,0);//(columna,fila)
      lcd.print(distancia);//imprime la distacnia en cm en el lcd
      lcd.setCursor(8,0);
      lcd.print("cm");
      delay(250);
      
    }
  }
 }
  
}
