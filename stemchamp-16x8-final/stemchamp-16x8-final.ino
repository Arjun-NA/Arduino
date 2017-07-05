int PIN_LATCH=8,mirror=0,upsideDown=1;
#include <SPI.h>
uint8_t C=B11111111;
void chartoarray(char,int array[]);
void showin(int X[],char c);
void matrix(int M[8][8],int tmax);


void setup()
{ 
  pinMode(PIN_LATCH, OUTPUT);
  SPI.begin();
  if(mirror)
  SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
  else
  SPI.beginTransaction(SPISettings(20000000, LSBFIRST, SPI_MODE0));
} 

void loop() 
{ int combined[8][16]= {
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
         999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,
};
stemchamp(999,10);
 } 
