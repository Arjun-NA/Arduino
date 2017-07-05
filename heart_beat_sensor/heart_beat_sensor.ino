const int sensorPin=A1,lowthr=500,upthr=700;
/* 
 * sensorPin  :- is the pin to which the sensor is connected A0,A1,A2.. A5 
 * refVal     :- is the value that represent the analog value when the Heart is Beating.
 * duration   :- is the time duration in seconds for which the pulse is taken; i.e,
 *               if the duration is 10s(case taken here) => for 60s we just multiply 6,  
 *               to the count recieved uptil then, to get HB( Heart beat rate ).
   */
void setup() 
{
Serial.begin(9600);
}


int val,i=0,HB=0,count=0,Tp;
unsigned long int t1=0,t2=0;
/*  val       :- variable for reading the analog value.
 *  HB        :- Heart Beat Rate.
 *  count     :- Heart beat counted in the time interval of the duration.
 *  counted   :- boolean variable to avoid counting a beat twice, like counting 
 *               a pulse twice bcs of the analog read reading twice or more before 
 *               compleating one beat.
 */

void loop() 
{
 val=analogRead(sensorPin);                              // reading the analog Value
 if(val<upthr)                                          // if there is a beat ( val >= upthr indicate presence of beat) 
 {  while(val<upthr)
       val=analogRead(sensorPin); 
    t1 = millis();    
    while(val>=upthr)
       val=analogRead(sensorPin);                       
    while(val<upthr)
        val=analogRead(sensorPin);                                      
    t2=millis();
 }
               
 Tp=(t2-t1);
 HB=60*1000/Tp;    
 if(HB>40&&HB<100)
 {
 Serial.print("Heart beat rate =  ");                          // OUTPUT
 Serial.println(HB);
 }
 else
 Serial.println("Waiting..");
}
