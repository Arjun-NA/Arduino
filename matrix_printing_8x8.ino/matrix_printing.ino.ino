void setup() {
 Serial.begin(9600);
}
const byte IMAGES[][8]= {
  {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B00111100,
  B00000110,
  B01100110,
  B00111100
  },{
  B00000000,
  B01111110,
  B01011010,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
  },{
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01111110
  },{
  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01100011,
  B01100011,
  B01100011,
  },{
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01100000,
  B01100110,
  B00111100,
  },{
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
  },{
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
  
  },{
  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01100011,
  B01100011,
  B01100011,
  },{
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
  }};
int scroll[8][24]={
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,};
  int fin[8][16]={
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  }; 
  void loop()
  {
  byte var;
  for(int f=0;f<9;f++)
  {     for(int i=0;i<8;i++)
        {     for(int j=0,var=IMAGES[f][i];j<8;j++,var/=2)
                  scroll[i][23-j]=999*(var%2);
    /* for(int j=0;j<8;j++)
     {  Serial.print(scroll[i][j+16]);
        Serial.print("\t");
       
     }
     Serial.println("|");*/
        }
        for(int n=0;n<8;n++)
        {     for(int k=0;k<8;k++)
              {     for(int l=0;l<23;l++)
                        scroll[k][l]=scroll[k][l+1]; 
                    scroll[k][23]=0;
              }  
              for(int i=0;i<8;i++)
              {     for(int j=0;j<16;j++)
                    {  fin[i][j]=scroll[i][j];
                       Serial.print(fin[i][j]);
                       Serial.print("\t");
       
                    }
                    Serial.println("|"); 
              }
              delay(1000);
        }
  }/*
    for(int i=0;i<8;i++)
     { for(int j=0;j<16;j++)
      { fin[i][j]=scroll[i][j]; 
       Serial.print(fin[i][j]);
       Serial.print("");
      }
      Serial.println("|");
     } 
     
   
   
   delay(10000);
  }}
   /*for(int k=0;k<8;k++)
   { for(int l=0;l<23;l++)
       {scroll[k][l]=scroll[k][l+1];matrix(scroll,tin);  }
     scroll[k][23]=0;
     for(int i=0;i<8;i++)
      for(int j=0;j<16;j++)
       fin[i][j]=scroll[i][j]; 
     
  }*/
}
