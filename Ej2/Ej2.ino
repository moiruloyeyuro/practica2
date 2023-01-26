#include <Arduino.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mySensor;
float aX, aY, aZ;
int cont;
int i=0;
const int SDA_PIN=21;
const int SCL_PIN=22;
const int pinLED=26;
uint8_t result;


void loop3(void *parameter) {
    digitalWrite(pinLED,HIGH);
    delay(200);
    digitalWrite(pinLED,LOW);
    delay(800);
    vTaskDelete( NULL );
}


void loop2(void *parameter) {
    Serial.println("accelX: " + String(aX));
    Serial.println("accelY: " + String(aY));
    Serial.println("accelZ: " + String(aZ));
    Serial.println("");
       xTaskCreate(loop3, "loop3", 15000, NULL, 3, NULL);
    vTaskDelete( NULL );
  }



void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);
  mySensor.beginAccel();
}

void loop() {
    for( cont = 0; cont < 10; cont ++){
      result = mySensor.accelUpdate();
      aX = mySensor.accelX();
      aY = mySensor.accelY();
      aZ = mySensor.accelZ();
      delay(100);
    }
    xTaskCreate(loop2, "loop2", 15000, NULL, 2, NULL);
    }
