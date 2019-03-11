#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
    string in1,in2,in;
int waset[8][8]={0};
int result[8]={0};
int MulResult=0;
    int x=0,y=0,m=0,yy=0;
    int q=27;
    string s;

void ConvertToBinary(int BinaryNum[],string in){
    for(int i=0;i<2;i++){
            s=in[i];
if((s=="A")||(s=="B")||(s=="C")||(s=="D")||(s=="E")||(s=="F"))
  {
      if(s=="A"){
     BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=0;
     BinaryNum[i*4+2]=1;
     BinaryNum[i*4+3]=0; }
     else if(s=="B")
     {
     BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=0;
     BinaryNum[i*4+2]=1;
     BinaryNum[i*4+3]=1;
     }
     else if(s=="C")
     {
     BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=1;
     BinaryNum[i*4+2]=0;
     BinaryNum[i*4+3]=0;
     }
     else if(s=="D")
     {
    BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=1;
     BinaryNum[i*4+2]=0;
     BinaryNum[i*4+3]=1;
     }
      else if(s=="E")
     {
    BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=1;
     BinaryNum[i*4+2]=1;
     BinaryNum[i*4+3]=0;
     }
      else if(s=="F")
     {
    BinaryNum[i*4]=1;
     BinaryNum[i*4+1]=1;
     BinaryNum[i*4+2]=1;
     BinaryNum[i*4+3]=1;
     }
  }
  else
    {
        y=atoi(s.c_str());
        for(int x=3;x>=0;x--)
        {
        BinaryNum[i*4+x]=y%2;
        y=y/2;
        }
    }

  }
  }
int main()
{
    int TheNum[8]={0,0,0,1,1,0,1,1};
    int BinaryNum1[8]={0};
    int BinaryNum2[8]={0};
    int SumResult[8]={0};
    int sum=0;
    int zz=0;
    int c=0;

    cin>>in1;
    cin>>in2;

    ConvertToBinary(BinaryNum1,in1);
    for(int i=7;i>=0;i--)
        {
            if(BinaryNum1[i]==1){
           x=x+ pow(2,c);
           }
           c++;
        }
    c=0;
    ConvertToBinary(BinaryNum2,in2);
    for(int i=7;i>=0;i--)
        {
            if(BinaryNum2[i]==1){
           yy=yy+ pow(2,c);
           }
           c++;
        }
      for(int i=0;i<8;i++)
        {
           SumResult[i]= BinaryNum1[i]^BinaryNum2[i];
        }

         c=0;
        for(int i=7;i>=0;i--)
        {
            if(SumResult[i]==1){
           sum=sum+ pow(2,c);
           }
           c++;
        }

        printf("%02X",sum);
        cout<<" ";
    if (x==0||yy==0)
        printf("%02X",0);
    else if(yy==1)
    {
        printf("%02X",x);
    }
    else if(x==1)
    {

        printf("%02X",yy);
    }
    else if(x>=yy){
            for (int n=0;n<8;n++){
                waset[0][n]=BinaryNum2[n];
                }
            for(int i=1;i<8;i++)
            {
                    zz=BinaryNum2[0];
                         for(int v=0;v<7;v++){
                        BinaryNum2[v]=BinaryNum2[v+1];
                        }
                        BinaryNum2[7]=0;
                    if(zz==1)
                        {
                            for(int k=0;k<8;k++){
                                BinaryNum2[k]=BinaryNum2[k]^TheNum[k];
                    }
                }
                 for (int n=0;n<8;n++){
                waset[i][n]=BinaryNum2[n];
                }
                }

            for(int t=0;t<8;t++){
                for(int j=0;j<8;j++){
                    if(BinaryNum1[7-t]==1)
                    {
                      result[j]= result[j]^waset[t][j];
                    }
                }
            }
            c=0;
        for(int i=7;i>=0;i--)
        {
            if(result[i]==1){
           MulResult=MulResult+ pow(2,c);
           }
           c++;
        }

        printf("%02X",MulResult);}

    else if(x<yy){
            for (int n=0;n<8;n++){
                waset[0][n]=BinaryNum1[n];
                }
            for(int i=1;i<8;i++)
            {
                    zz=BinaryNum1[0];
                         for(int v=0;v<7;v++){
                        BinaryNum1[v]=BinaryNum1[v+1];
                        }
                        BinaryNum1[7]=0;
                    if(zz==1)
                        {
                            for(int k=0;k<8;k++){
                                BinaryNum1[k]=BinaryNum1[k]^TheNum[k];
                    }
                }
                 for (int n=0;n<8;n++){
                waset[i][n]=BinaryNum1[n];
                }
                }

            for(int t=0;t<8;t++){
                for(int j=0;j<8;j++){
                    if(BinaryNum2[7-t]==1)
                    {
                      result[j]= result[j]^waset[t][j];
                    }
                }
            }
            c=0;
        for(int i=7;i>=0;i--)
        {
            if(result[i]==1){
           MulResult=MulResult+ pow(2,c);
           }
           c++;
        }

        printf("%02X",MulResult);

    }





    return 0;
}
