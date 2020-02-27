void setup() {
//Libraries
#include <SoftwareSerial.h>

//variables

//light sensors
#define lightSensor A0  //analog pin 0
int lightSensorStatus = 0;

//HC-05 bluetooth module
int bluetoothStatus = 0; //if the bluetooth module is being called
SoftwareSerial bluetooth (10, 11); //serial communication for the RX and TX pins


void setup() {
  // put your setup code here, to run once:
  //light sensor

  //bluetooth module
  Serial.begin(9600); //begin the serial communication
  bluetooth.begin(38400); //default serial port for the bluetooth module

}

void loop() {
  // put your main code here, to run repeatedly:
  //if the bluetooth is available
  if(bluetooth.available)
  {
    //check if the Mother Russia code wants to check the light sensor value
    bluetoothStatus = bluetooth.read();
     
    //check the status of the light sensor
    lightSensorStatus = analogRead(lightSensor);
 
    //if it is too dark
    if(lightSensorValue < 50)
    {
      //bluetooth.write(lightSensorStatus);
      bluetooth.write('Too Dark');
      Serial.print('Too Dark');
    }
    //if it is too bright
    else if(lightSensorValue > 100)
    {
      //bluetooth.write(lightSensorStatus);
      bluetooth.write('Too Bright');
      Serial.print('Too Bright');
    }
 
    //default brightness
    else
    {
      //bluetooth.write(lightSensorStatus);
      bluetooth.write('default');
      Serial.print('default');
    }
   
  }
 

}
