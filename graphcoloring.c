#include<stdio.h>
#include<stdlib.h>

int m=4;
int val[4] = {1,1,1,1};
int tot=0;
int n=5;
int x[5]={0,0,0,0,0};
int g[5][5]={{0,1,1,1,1},{1,0,1,0,0},{1,1,0,1,0},{1,0,1,0,1},{1,0,0,1,0}};
void nextvalue(int);
void ncolor(int);
int min(void);

int main()
{
  printf("Possible Solutions : \n");
  ncolor(1);
  printf("Total no of Possible Solutions : %d",tot);
}

int min()
{
  int total=0;
  for(int i=0;i<m;i++)
  {
    total+=val[x[i]-1];
  }
  return total;
}

void nextvalue(int k)
{
  while(1)
  {
    x[k-1]=(x[k-1]+1)%(m+1);
    if(x[k-1]==0)
    {
      return;
    }
    int j; 
    for(j=1;j<=n;j++)
    {
      if((g[k-1][j-1]!=0) && (x[k-1]==x[j-1]))
      {
        break;
      }
    }
    if(j==n+1)
    {
      return;
    }
  }
}

void ncolor(int k)
{
  while(1)
  {
    nextvalue(k);
    if(x[k-1]==0)
    {
      return;
    }
    if(k==n)
    {
      for(int i=0;i<n;i++)
      {
        printf("%d ",x[i]);
      }
      printf("\nCost : %d\n",min());
      tot+=1;
      printf("\n");
    }
    else
    {
      ncolor(k+1);
    }
  }
}
