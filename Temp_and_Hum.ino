
// Author: TechZx
//Project: LCD Temp/Hum sensor for pc case
// LCD brightness can be setted with the potentiometer attached to it if you are using one like in the example given

#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
dht DHT;
#define DHT11_PIN 7
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);  // initializing  LCD
  lcd.begin();
  lcd.setBacklight((uint8_t)1);// Turn on the blacklight
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.print("Temperature = ");
  Serial.print("Temperature = ");
  lcd.println(DHT.temperature);
  Serial.println(DHT.temperature);
  lcd.print("Humidity = ");
  Serial.print("Humidity = ");
  lcd.println(DHT.humidity);
  Serial.println(DHT.humidity);
  delay(10000);
  lcd.clear(); 
}
