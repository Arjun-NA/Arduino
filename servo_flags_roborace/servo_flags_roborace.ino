#include <Servo.h> 
Servo flag[3];   

long int t,x[3],time[4]={2,3,4,5};        // Timings of Each flag
int i=0,val,toggle[4]={0,0,0,0},y[3],dly=1,fspeed=1;      // Delay , initialisations

void flag_to(int x,int pos)         // x th flag to pos degrees    
{  if(!pos)                        // Assuming only two cases
      for(i=90;i>=0;i-=fspeed)
        flag[x].write(i);
    else
      for(i=0;i<=90;i+=fspeed)
        flag[x].write(i);
}

void flags(int a)
{ 
  if(t==time[a]&&!y[a])
   { 
     flag_to(a,90);
     y[a]=1;
     x[a]=1;
     
   }
  val=time[a]+x[a]*5;
  
  if(y[a]&&t>=val)
  {  Serial.print("toggle");
     x[a]++;
     toggle[a]=!toggle[a];
     if(toggle[a])
       flag_to(a,0);
     else
       flag_to(a,90);  
  }
}

void setup() 
{ 
  flag[0].attach(3);
  flag[1].attach(5);
  flag[2].attach(9); 
  flag_to(0,0);
  flag_to(1,0);
  flag_to(2,0);
  Serial.begin(9600);
} 
  
void loop() 
{ 
  t=millis();
  t/=1000;
  Serial.println(t);
  flags(0);
  flags(1);
  flags(2);
 
  delay(10);                            
} 

