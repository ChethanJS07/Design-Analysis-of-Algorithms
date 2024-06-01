#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int place(int, int);
void nqueen(int ,int);


int n=4;
int x[4];


int place(int k,int i)
{
  for(int j=1;j<k;j++)
  {
    if(abs(x[j-1]-i) == abs(j-k))
    {
      return 0;
    }
  }
  return 1;
}

void nqueen(int k,int n)
{
  for(int i=1;i<=n;i++)
  {
    if(place(k,i))
    {
      x[k-1]=i;
      if(k==n)
      {
        for(int j=0;j<n;j++)
        {
          printf("%d ",x[j]);
        }
        printf("\n");
      }
      else
      {
        nqueen(k+1,n);
      }
    }
  }
}

int main()
{
  nqueen(1,n);
}
