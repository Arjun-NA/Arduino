#include <SPI.h>

#define ip 12

const int slaveSelect= 10; //pin used to enable the active slave
int num_arr1[3], num_arr2[3], num_arr3[3], num_arr4[3], num1, num2, num3, num4,count,result;
static int cmp=0;
long key;
byte input[ip]={2,3,4,5,6,7,8,9,12,14,15,16};
const int numberofDigits= 4;
static bool flag,flag2;
void sendCommand(int command, int value)
{
digitalWrite(slaveSelect, LOW); //chip select is active low
SPI.transfer(command);
SPI.transfer(value);
digitalWrite(slaveSelect,HIGH);
}
//function to display up to 4 digits on a 7-segment display
void displayNumber (int number)
{
  for (int i=0; i<numberofDigits; i++)
  {
    byte character= number % 10; //get the value of the rightmost digit
    sendCommand(numberofDigits-i, character);
    number= number/10;
  } 
}
int keys() 
{   num1 =num2 = num3 = num4 = 0;
    for(int i=0;i<ip;i++)
    { 
      if(i<3)
      {
       num_arr1[i]= digitalRead(input[i]);
      }
      if((i>=3)&&(i<6))
      {
         num_arr2[i-3]= digitalRead(input[i]);        
         //num2 = num(num_arr2);
      }
      if((i>=6)&&(i<9))
      {
         num_arr3[i-6] = digitalRead(input[i]);
        //num3 = num(num_arr3);
      } 
      if((i>=9)&&(i<12))
      {
          num_arr4[i-9] = digitalRead(input[i]);
          //num3 = num(num_arr3);
      } 
    
  }
  num1 = num(num_arr1);
  num2 = num(num_arr2);
  num3 = num(num_arr3);
  num4 = num(num_arr4);
  if(iskeyinserted()==true)
  {
    key=(long)((1000*num1)+(100*num2)+(10*num3)+(1*num4));
  }
  Serial.println(key);  
  result=keycomp(key);
  Serial.println(result);
  delay(200);
}


/**********************************************************
 * *************function for all key inserted or not******
 *********************************************************/

int iskeyinserted()
{
 if(num1!=7 && num2!=7 && num3!=7 && num4!=7)
  {
    return true;
   
  }
  else
  { flag=false;
    return false;
    
  }
}

/*************************************************************
**************function definition keycomp ********************
*************************************************************/

int keycomp(long key)
{
   int keyset[4]={6666,4444,3333,4444};
   
   if(iskeyinserted())
   {     if(keyset[cmp] == key)
         {  flag2=true;
            Serial.print("true\t");
            Serial.println(cmp);
            return true;
         }
         else
         {  
            Serial.println("false");
            return false;
         }
   }
   else
   {   if(flag2)
       { flag2=false;  cmp++;
       }
       return true;
   }
      
}

/*************************************************************
**************function definition num ************************
*************************************************************/

int num(int* num_arr)
{

   int num;

   num=(int)((num_arr[0]*4)+(num_arr[1]*2)+(num_arr[2]*1));
   switch(num)
   {
       case 0:
          num=7;
          break;
       case 1:
          num=3;
          break;
       case 2:
          num=6;    
          break;
       case 3:
          num=1;
          break;
       case 4:
          num=4;
          break;
       case 5:
          num=5;       
          break;
       case 6:
          num=2;
          break;
       case 7:
          num=8;
          break;
   }
   return num;
}



bool stp;
void setup()
{
  Serial.begin(9600); 
  SPI.begin();
  SPI.beginTransaction(SPISettings(2000,MSBFIRST,SPI_MODE0)); //initialize SPI
  pinMode(slaveSelect, OUTPUT);
  digitalWrite(slaveSelect, LOW); //select Slave
  
  //prepare the 7219 to display 7-segment data
  sendCommand (12,1); //normal mode (default is shutdown mode)
  sendCommand (15,0); //Display test off
  sendCommand (10,8); //set medium intensity (range is 0-15)
  sendCommand (11, numberofDigits); //7219 digit scan limit command
  sendCommand (9,0b11111111); //decode command, use standard 7-segment digits
  digitalWrite(slaveSelect, HIGH); //deselect slave
}
unsigned long s;
long timer1=3600,timerfin;
int minutes,seconds;
int displaynumber;
void loop()
{
  //display a number from serial port terminated by end of line character
  if(!stp&&cmp!=4)
  s=millis()/1000;
  timerfin=timer1-s; 
  keys();
  if(keycomp(key)==false&&!flag)
  {
    timer1-=300;
    flag=true;
  }
  
  Serial.println(keycomp(key));
  minutes=timerfin/60;
  seconds=timerfin%60;
  displaynumber=minutes*100+seconds;
  if(displaynumber<=0)
  { displaynumber=0;
    stp=true;
  }  
  Serial.println(displaynumber);
  displayNumber(displaynumber);

}

