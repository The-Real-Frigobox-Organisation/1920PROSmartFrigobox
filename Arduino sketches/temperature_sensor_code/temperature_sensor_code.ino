#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int analogInPin = A5; 

// Deze waarden moeten worden gecallibeerd per 'sensor (voltage devider)'
// https://www.youtube.com/watch?v=GCNyZt_vZW4

const int SensorValueLow = 520; 
const int SensorValueDiff = 35; // differance between high and low sensor value
const int TempValueDiff = 39; // differance between high and low Temp value
const int TempValueLow = 5;

int sensorValue = 0;
double Temp = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() 
{
  //Deze code kan in een functie worden geplaatst om makkelijk een array van 8 temperaturen op te bouwen
  sensorValue = analogRead(analogInPin);
  Temp = sensorValue-SensorValueLow;
  Temp = Temp/SensorValueDiff;
  Temp = Temp*TempValueDiff;
  Temp = Temp+TempValueLow;

  lcd.setCursor(0,0);
  lcd.print("Value = ");
  lcd.setCursor(8,0);
  lcd.print(sensorValue);

  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.setCursor(7,1);
  lcd.print(Temp);

  delay(200);
}
