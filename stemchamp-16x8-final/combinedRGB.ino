void matrix(int M[8][16],int tmax)
{ int R[8][16],G[8][16],B[8][16],i,j,t;
  for(int i=0;i<8;i++)
   for(int j=0;j<16;j++)
   { R[i][j]=M[i][j]/100;
     G[i][j]=(M[i][j]/10)%10;
     B[i][j]=M[i][j]%10;
   }

  for(int t=0;t<tmax;t++)
   gen(R,G,B);   
}

