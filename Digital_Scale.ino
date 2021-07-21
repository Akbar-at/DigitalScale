#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
#include <HX711_ADC.h>
HX711_ADC LoadCell(4, 5); 
LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
{'1','2','3',},
{'4','5','6'},
{'7','8','9'},
{'C','0','T','K'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; 
byte colPins[COLS] = {7, 6, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int a = 0;
long b = 0;
int c = 0;
int Num1,Num2,Number;

void setup() {
Serial.begin(9600);
lcd.init(); 
lcd.backlight(); 
lcd.print("Starting......");
lcd.setCursor(0, 1);
lcd.print("M Akbar Attallah");
LoadCell.begin();
LoadCell.start(1000); 
LoadCell.setCalFactor(214.2       ); // 
lcd.clear();
}

void loop() {

char key = keypad.getKey();
if ((key)&&(c<4))
{

if (key == '1')
{
if (Number==0)
Number=1;
else
Number = (Number*10) + 1; 
}
if (key == '2')
{
if (Number==0)
Number=2;
else
Number = (Number*10) + 2;
}
if (key == '3')
{
if (Number==0)
Number=3;
else
Number = (Number*10) + 3; 
}
if (key == '4') 
{
if (Number==0)
Number=4;
else
Number = (Number*10) + 4; 
}
if (key == '5')
{
if (Number==0)
Number=5;
else
Number = (Number*10) + 5; 
}
if (key == '6')
{
if (Number==0)
Number=6;
else
Number = (Number*10) + 6; 
}
if (key == '7') 
{
if (Number==0)
Number=7;
else
Number = (Number*10) + 7; 
}

if (key == '8')
{
if (Number==0)
Number=8;
else
Number = (Number*10) + 8; 
}

if (key == '9')
{
if (Number==0)
Number=9;
else
Number = (Number*10) + 9; 
}

if (key == '0')
{
if (Number==0)
{
Number=0;
c = c - 1;
}
else
Number = (Number*10) + 0; 
}
c = c + 1;
}

if (key=='C') 
{
Number=0;
c = 0;
lcd.setCursor(9, 1);
lcd.print("0   ");
}

LoadCell.update(); 
float i = LoadCell.getData(); 
lcd.setCursor(9, 1); 
lcd.print(Number);
delay(1);
lcd.setCursor(2, 3); 
lcd.print("Price = ");
b = (i* Number/1000);
if(b<0)
{
b=0;
}
lcd.setCursor(10, 3); 
lcd.print(b, 1); // 
lcd.print(" ");

lcd.setCursor(0, 0); 
lcd.print("W(grams)="); 
lcd.print(i, 1); 

lcd.setCursor(0, 1);
lcd.print("Price/KG=");

float k = i/1000;

lcd.setCursor(1, 2); 
lcd.print("Weight = ");

if (k>=20)
{
lcd.setCursor(1, 2); 
lcd.print("Over Loaded ");
delay(100);
}

if (key=='T')
{

lcd.setCursor(0, 1); 
lcd.print(" Taring... ");
LoadCell.start(1000);
lcd.clear();


}
if (key =='K')
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Price=Rp");
  lcd.print(b,1);
  delay(1000);
  lcd.clear();
}
}
