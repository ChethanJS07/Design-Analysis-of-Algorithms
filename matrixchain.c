#include<stdio.h>

void matrix(int P[],int n)
{
  for(int i=0;i<n;i++)
  {
    m[i,i]=0;
  }
  for(int l=1;l<n;l++)
  {
    for(int i=0;i<n-l;i++)
    {
      int j = i+l-1;
      m[i,j]=9999999;
      for(int k=i;k<j;k++)
      {
        int q = m[i,k]+m[k+1,j]+P[i-1]*P[k]*P[j];
        if(q<m[i,j])
        {
          m[i,j]=q;
          s[i,j]=k;
        }
      }
    }
  }
  print(n);
}

void print(int i,int j)
{
  if(i==j)
  {
    printf("A%d",i);
  }
  else
  {
    printf("(");
    print(i,s[i,j]);
    print(s[i,j]+1,j);
    printf(")");
  }
}