int sumanum=0;
void setup() {
  pinMode(3,INPUT_PULLUP);
  //PULLUP AYUDA A EVITAR LOS REBOTES EN SEÑAL
  Serial.begin(9600);
  //inicia monitor serial(esquina superior derecha)
  //9600 se puede cambiar si cambiamos también el número en el monitor
  //Verificar documentación para saber qué poner
}
void loop() {
  while(digitalRead(3)==HIGH){
    //Usamos un While para que no sume si mantienes presionado el boton
    if(digitalRead(3)==LOW){
      sumanum+=1;
      Serial.println(sumanum);
      delay(300);
    }
  }
}
