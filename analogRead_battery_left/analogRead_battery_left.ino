#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int led=7;
int top;
float high, percentage;
void setup() 
{
    Serial.begin(9600);
    pinMode(led,OUTPUT);
    lcd.begin(16, 2);
}

void loop() 
{
  top=analogRead(A1);
  high=top*(5000/1023);
  percentage=(high/4500)*100;
  lcd.setCursor(0, 0);
  lcd.print("Battery Left:");
  lcd.setCursor(0, 1);
  lcd.print(percentage);
  lcd.print("%");
}
