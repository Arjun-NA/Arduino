
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);
char bluetoothdata,control[20];
char fanon[6]={'f','a','n',' ','o','n'};
char fanoff[7]={'f','a','n',' ','o','f','f'};
char lighton[8]={'l','i','g','h','t',' ','o','n'};
char lightoff[9]={'l','i','g','h','t',' ','o','f','f'};
float temp=0;int j,k,l,m;
int tempPin = A0,ldr= A1,humPin=A2,hu=0,ldru=0,humid=0,lux=0;
float humidity[15]={3.99,3.98,3.96,3.92,3.84,3.70,3.44,3.137,2.81,2.305,1.8,1.2,0.84,0.4};
// Values above are borrowed by calcutaions done from the knowledge provided in the data sheet.
float hv=0,ldrv=0;
float luxin[10]={2.19,2.8,3.22,3.53,3.77,3.96,4.12,4.25,4.36,4.46};
// Values above where calculated from a model created in protues .
void setup()
{
   Serial.begin(9600);   
   bluetooth.begin(9600);
   pinMode(2,OUTPUT); 
   pinMode(3,OUTPUT);  // Setting up  , Initialising ....
}
void input()                               // Function for taking 
{                                         // inputs from analog pins.
  hu=analogRead(humPin);
  hv=map(hu,0,1023,0,5); 
  ldru=analogRead(ldr);
  ldrv=map(ldru,0,1023,0,5);
  temp = analogRead(tempPin);
}

void calculate()
// Function to Calculate to real values
{ 
        
  temp = temp * 0.48828125;                // Default calculation of lm35
  for(humid=0;hv<humidity[humid];humid++);
  /* Finding humidity through finding the almost from known values.
     After the execution of the for loop the value of humid is given
     a realtable value by determination of values from the table of 
     values prodused by the DataSheet of Humidity Sensor HR202 */
  for(lux=0;ldrv>luxin[lux];lux++);    
  /* Similarly, luminous intensity value is found out. here protues 
     was used to determine the diffrent values of LUX relating to volts */  
  humid=(humid+4)*5;  // Finally actual exact values are determined with simple calculations
  lux=(10-lux)*5;      //   "            "               "             "
}
void controls()
{
if(bluetooth.available())
  { j=k=l=m=0;
     for(int i=0;i<10;i++)
      {
        bluetoothdata=bluetooth.read();
        control[i]=bluetoothdata;
      }
      for(int i=0;i<9;++i)
      {
         if(control[i]==fanon[i])
          j++;
         if(control[i]==fanoff[i])
          k++;
         if(control[i]==lighton[i])
          l++;
         if(control[i]==lightoff[i])
          m++; 
      }   
     if(j==6)
      {  bluetooth.println("fan turned on");
      delay(100);
         digitalWrite(2,1);
      }  
     if(k==7)
      {  bluetooth.println("fan is turned off");
         delay(100);
         digitalWrite(2,0);
      }
     if(l==8)
      {  bluetooth.println("light is tured on");
         delay(100);
         digitalWrite(3,1);
      }  
     if(m==9)
      {  bluetooth.println("light is turned off");
         delay(100);
         digitalWrite(3,0);
      }
  } 
}  
         
// Functions to Output the Required values in the Serial Monitor
void show()
{
  bluetooth.print("TEMPRATURE = ");
  bluetooth.print(temp);
  bluetooth.println("*C");
  delay(100);
  bluetooth.print("Luminous indencity =");
 lux=analogRead(A1);
  bluetooth.print(lux);
  bluetooth.println("  LUX");
  
  delay(100);
  bluetooth.print(" Humidity = ");
  bluetooth.print(humid);
  bluetooth.println("  % HR");
  delay(100);
  bluetooth.println();

  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.println("*C");
  Serial.print("Luminous indencity =");
  Serial.print(lux);
  Serial.println("  LUX");
  Serial.print(" Humidity = ");
  Serial.print(humid);
  Serial.println("  % HR");
  Serial.println();

}  
void loop()
{
  input();
  calculate();
  show();
  controls();
  
  delay(2000);          // Dealay of 3 secs is between each measurements.
}
