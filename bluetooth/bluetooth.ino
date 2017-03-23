// This program shown how to control arduino from PC Via Bluetooth
// Connect ...
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);// import the serial library

SoftwareSerial bluetooth(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
char BluetoothData; // the data given from Computer

void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  // put your setup code here, to run once:
  bluetooth.begin(9600);
  Serial.begin(9600);
  bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  // put your main code here, to run repeatedly:
   if(bluetooth.available())
   {
   BluetoothData=bluetooth.read();
   Serial.println(BluetoothData);
   lcd.print(BluetoothData);
   }



delay(100);// prepare for next data ...
}

