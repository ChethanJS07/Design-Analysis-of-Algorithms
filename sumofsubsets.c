#include<stdio.h>
#include<stdlib.h>

int n=6;
int w[7]={5,10,12,13,15,18};
int x[7]={0,0,0,0,0,0};
int sum=30;
void suos(int ,int ,int);

int main()
{
  int m=0;
  for(int i=0;i<n;i++)
  {
    m+=w[i];
  }
  suos(0,0,m);
}

void suos(int s,int k,int r)
{
  //Left child
  x[k]=1;
  if(s+w[k]==sum)
  {
    for(int i=0;i<n;i++)
    {
      printf("%d ",x[i]);
    }
    printf("\n");
  }
  else if(s+w[k]+w[k+1]<=sum)
  {
    suos(s+w[k],k+1,r-w[k]);
  }
  //Right Child
  if(s+r-w[k]>=sum && s+w[k+1]<=sum)
  {
    x[k]=0;
    suos(s,k+1,r-w[k]);
  }
}