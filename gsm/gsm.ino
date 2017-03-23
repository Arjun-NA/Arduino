#include<SoftwareSerial.h>
SoftwareSerial GPRS(5, 6);

void setup()
{
  GPRS.begin(9600);               // the GPRS baud rate
  Serial.begin(9600);             // the Serial port of Arduino baud rate.
  delay(500);
}

void loop() {
 if(Serial.available())  // If the temperature crosses the threshold, send the SMS
  {  sendSMS();
    Serial.println("Sent SMS!");
  }
  delay(10);
}

void sendSMS() {
  GPRS.println("AT+CMGF=1");    // Set modem to text mode
  delay(2000);
  GPRS.write("AT+CMGS=");      // Start composing message
  GPRS.write(0x22);            // hex equivalent of double-quote '"'
  GPRS.write("+919497838990"); // the number to send the SMS to
  GPRS.write(0x22);
  GPRS.write(0x0D);            // hex equivalent of Carraige return    
  GPRS.write(0x0A);            // hex equivalent of newline
  delay(2000);
  GPRS.print("MSG FROM");
  GPRS.write(0x0D);            // hex equivalent of Carraige return    
  GPRS.write(0x0A);            // hex equivalent of newline  
  delay(1000);
  GPRS.write(26);              // equivalent of CTRL-Z
  delay(3000);

}
