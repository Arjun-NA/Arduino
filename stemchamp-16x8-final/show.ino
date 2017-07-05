void show(uint16_t X[],uint16_t Y[],uint16_t Z[])
{ uint8_t Xa[8],Xb[8],Ya[8],Yb[8],Za[8],Zb[8];
  for(int i=0;i<8;i++)
  {   Xa[i]=X[i]%256;
      Xb[i]=X[i]/256;
      Ya[i]=Y[i]%256;
      Yb[i]=Y[i]/256;
      Za[i]=Z[i]%256;
      Zb[i]=Z[i]/256;  
  }
  int C;
  (!upsideDown)?C=B00000001:C=B10000000;
  for(int i=0;i<8;)
  {
   digitalWrite(PIN_LATCH, LOW);
   SPI.transfer(C);
   SPI.transfer(~Xb[i]);
   SPI.transfer(~Yb[i]);
   SPI.transfer(~Zb[i]);
   SPI.transfer(C);
   SPI.transfer(~Xa[i]);
   SPI.transfer(~Ya[i]);
   SPI.transfer(~Za[i]);
   
   digitalWrite(PIN_LATCH, HIGH);
   if(!upsideDown){
      if(i==6)
      { i=1;    C=B00000010; }
      else
      { i+=2;   C<<=2; }
   }
   else
   {  if(i==6)
      { i=1;    C=B01000000; }
      else
      { i+=2;   C>>=2; }
   }
   }
  digitalWrite(PIN_LATCH, LOW);
  SPI.transfer(C);
  SPI.transfer(~0);
  SPI.transfer(~0);
  SPI.transfer(~0);
  SPI.transfer(C);
  SPI.transfer(~0);
  SPI.transfer(~0);
  SPI.transfer(~0);
  digitalWrite(PIN_LATCH, HIGH);
  
}
