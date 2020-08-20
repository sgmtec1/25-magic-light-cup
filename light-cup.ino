//Open Source

#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int ledPinA = 9; // L
int switchPinA = 8; // S

int switchStateA = 0; //

int ledPinB = 6; // L
int switchPinB = 7;// S

int switchStateB = 0; //
int brightness   = 0; //

void setup() 
{
  pinMode(ledPinA, OUTPUT); 
  pinMode(ledPinB, OUTPUT);  
  pinMode(switchPinA, INPUT); 
  pinMode(switchPinB, INPUT);
  
  lcd.begin(16, 2);
  lcd.cursor();
}

void loop() 
{
  switchStateA = digitalRead(switchPinA);
  if (switchStateA == HIGH && brightness != 255)
  { 
   brightness ++;
   lcd.rightToLeft();   
   lcd.write("=====>> ");
  } 
  switchStateB = digitalRead(switchPinB);
  if (switchStateB == HIGH && brightness != 0)
  { 
   brightness --;   
   lcd.leftToRight();
   lcd.write("<<====");   
  } 
  analogWrite(ledPinA, brightness);
  analogWrite(ledPinB, 255 - brightness);
  delay(20);
}
