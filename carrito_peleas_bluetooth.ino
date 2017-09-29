int val;
int laser = 11;
int detector = 12;

int led1 = 15;
int led2 = 16;
int led3 = 17;
int vidas = 3;
boolean vivo = true;
  
void setup()
{
  Serial.begin(9600);
  pinMode(laser,OUTPUT);
  pinMode(detector,INPUT);
  delay(7000);
   
}
  
void loop() {
  
  int tag = digitalRead(detector);
  if(tag == 1){
    vidas--;
    delay(500);
  }
  if(vidas == 3){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
  if(vidas == 2){
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
   if(vidas == 1){
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  }
  if(vidas <= 0){
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    vivo = false;
  }
  
  if(vivo){
    if(Serial.available() >= 1)
    {
      char val = Serial.read();
      
       if(val == 'b'){
         digitalWrite(laser,HIGH);
      }
       if(val == 'v'){
         digitalWrite(laser,LOW);
      }
     
      if(val == 'a')
      {
        motores(250,250);
      }
      else if(val == 'i')  
      {
        motores(-250, 250);
      }
      else if(val == 's')
      {
        motores(0,0);
      }
      else if(val == 'r')
      {
        motores(-250,-250);
      }
      else if(val == 'd')
      {
        Serial.println(val);
        motores(250,-250);
      }
    }
   }
  }

 void motores(float m1, float m2)
{
   //m1 y m2 son las velocidades del primer
   // y segundo motor, entre -255 y 255
 
   //Declarar los pines para el motor 1
   pinMode(7, OUTPUT); //N1
   pinMode(8, OUTPUT); //N2
   pinMode(10, OUTPUT); //ENA
    
   //Declarar los pines para el motor 2
   pinMode(2, OUTPUT);  //N3
   pinMode(4, OUTPUT);  //N4
   pinMode(6, OUTPUT); //ENB
    
    
   //Invertir el giro del motor 1 si es necesario
   if(m1 < 0)
   {
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      m1 = -m1;
   }
   else
   {
      digitalWrite(8, LOW);
      digitalWrite(7,HIGH);
   }
    
 
   //Invertir el giro del motor 2 si es necesario
   if(m2 < 0)
   {
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      m2 = -m2;
   }
   else
   {
      digitalWrite(4, LOW);
      digitalWrite(2,HIGH);
   }
 
   //Generar pulso PWM
   analogWrite(10, m1);
   analogWrite(6, m2);
}
