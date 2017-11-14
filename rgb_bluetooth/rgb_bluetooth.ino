#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //10 RX, 11 TX.
 
int ledred=3; //Pin LED Red
int ledgreen=5;//Pin LED Green
int ledblue=6; //Pin LED Blue
 
void setup()
{
  Serial.begin(9600);//Inicialización de monitor Serial
  BT.begin(9600);  //Velocidad del puerto del módulo Bluetooth
 
  pinMode(ledred,OUTPUT);   //Pueto Digital utilizando la función PWM
  pinMode(ledgreen,OUTPUT);//Pueto Digital utilizando la función PWM
  pinMode(ledblue,OUTPUT);//Pueto Digital utilizando la función PWM
}
 
void loop()
{
    //Cuando haya datos disponibles
    while (BT.available()>0)
    {
        int red = BT.parseInt(); //Leemos el primer valor entero (Red) y lo almacenamos en la variable
 
        int green = BT.parseInt(); //Leemos el segundo valor entero (Green) y lo almacenamos en la variable
 
        int blue = BT.parseInt(); //Leemos el último valor entero (Blue) y lo almacenamos en la variable
       
        //Bloque para ver por monitor serial lo que está mandando android en resolución de 8 bits
        Serial.print("red: ");
        Serial.println(red);  
        Serial.print("blue: ");
        Serial.println(blue); 
        Serial.print("green: ");
        Serial.println(green);
        
        //Cuando lea el carácter fin de línea ('\n') quiere decir que ha finalizado el envío de los tres valores
        if (BT.read() == '\n')
        {
          //Enviamos los valores de los tres colores al LED RGB através de PWM
          analogWrite(ledred,red);
          analogWrite(ledgreen,green);
          analogWrite(ledblue,blue);
        }
  }
}
