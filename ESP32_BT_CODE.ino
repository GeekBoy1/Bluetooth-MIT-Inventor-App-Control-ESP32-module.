#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
 Serial.begin(115200);
 SerialBT.begin("ESP32_Device"); //Bluetooth device name
 pinMode(2,OUTPUT);
}

void loop() {
 if (Serial.available()) {
   SerialBT.write(Serial.read());
 }
 if (SerialBT.available()) {
   Serial.write(SerialBT.read());
 }
 delay(5);
 if(SerialBT.read() == 'a')
 {
digitalWrite(2,HIGH);
//Serial.println("Light On");
 }
 delay(5);
 if(SerialBT.read() == 'b')
 {
   digitalWrite(2,LOW);
   //Serial.println("Light Off");
 }
}
