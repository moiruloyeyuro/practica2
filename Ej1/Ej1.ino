#include <Arduino.h>
const int pinLED=26;
void setup() {
  pinMode(pinLED,OUTPUT);
  Serial.begin(112500);
  delay(1000);

  xTaskCreate(Tarea1,"Tarea1",10000,NULL,1,NULL);
  xTaskCreate(Tarea2,"Tarea2",10000,NULL,1,NULL);

}

void loop() {
  delay(1000);
}

void Tarea1( void * parameter )
{

    for( int i = 0;i<10;i++ ){

        Serial.println("Hola mundo");
        delay(1000);
    }
    vTaskDelete( NULL );

}

void Tarea2( void * parameter)
{

    for( int i = 0;i<25;i++ ){
        digitalWrite(pinLED,HIGH);
        Serial.println("on");
        delay(200);
        digitalWrite(pinLED,LOW);
        Serial.println("off");
        delay(200);
    }
    vTaskDelete( NULL );
}