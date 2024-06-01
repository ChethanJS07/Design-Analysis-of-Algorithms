#include<stdio.h>
#include<stdlib.h>

void naive(char[],int,char[],int);

int main()
{
  int n = 10;
  char T[] = {'2', '3', '5', '7', '2', '2', '0', '1', '1', '2','\0'};
  int m = 3;
  char P[] = {'2', '2', '0','\0'};
  naive(T,n,P,m);
}

void naive(char T[],int n,char P[],int m)
{
  for(int s=0;s<=n-m;s++)
  {
    int count=0;
    for(int i=0;i<m;i++)
    {
      if(P[i]!=T[s+i])
      {
        count=1;
        break;
      }
    }
    if(count==0)
    {
      printf("Patter occurs with shift %d\n",s);
    }
  }
}