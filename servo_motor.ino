// Incluímos la librería para poder controlar el servo
#include <Servo.h>
int led1 = 8;
int led2 = 10;
 
// Declaramos la variable para controlar el servo
Servo servoMotor;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
 
  // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(0);
}
 
void loop() {
 
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    digitalWrite(led1, HIGH);//servo ida
    digitalWrite(led2, LOW);
    //impresion de grados en puerto serie
    Serial.print("Grado :");
    Serial.println(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    digitalWrite(led2, HIGH);//servo regreso
    digitalWrite(led1, LOW);
    //impresion de grados en puerto serie
    Serial.print("Grado :");
    Serial.println(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
}
