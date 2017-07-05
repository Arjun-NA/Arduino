const byte PIN_LATCH = 11;
const byte PIN_CLOCK = 12;
const byte PIN_DATA  = 8;

byte R = B11111110,G=B00000000;
byte dir_forward = 1;

void setup()
{ 
  
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA , OUTPUT);
  digitalWrite(PIN_LATCH, LOW);
  shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, 0);
  digitalWrite(PIN_LATCH, HIGH);
  
} 

void loop() 
{ 
  
  digitalWrite(PIN_LATCH, LOW);
  shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, G);
  
  shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, R);
  if(dir_forward)
  { 
    R <<= 1;G>>=1;
    R++;
    G+=128;
    if(127 == R)
      dir_forward = 0;
  } 
  else
  { 
    R >>= 1; G <<= 1;
    R+=128;
    G++;
    if(254 == R)
      dir_forward = 1;
  } 
  digitalWrite(PIN_LATCH, HIGH);
  delay(100);
  
} 
