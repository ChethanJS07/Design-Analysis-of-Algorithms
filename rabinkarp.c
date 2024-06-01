#include <stdio.h>
#include <stdlib.h>

void rabin_karp(int n, char T[], int m, char P[], int d, int q);

int main()
{
  int n = 10;
  char T[] = {'2', '3', '5', '7', '2', '2', '0', '1', '1', '2','\0'};
  int m = 3;
  char P[] = {'2', '2', '0','\0'};
  int d = 10;
  int q = 11;
  rabin_karp(n, T, m, P, d, q);
  return 0;
}

void rabin_karp(int n, char T[], int m, char P[], int d, int q)
{
  int a_hit[n-m+1];
  int s_hit[n-m+1];
  int a_count=0;
  int s_count=0;
  int h = 1;
  for (int i = 0; i < m - 1; i++)
  {
    h = (h * d);
  }
  h = h%q;
  int p = 0;
  int t = 0;
  for (int i = 0; i < m; i++)
  {
    p = (d * p + P[i]) % q;
    t = (d * t + T[i]) % q;
  }

  for (int s = 0; s <= n - m; s++)
  {
    if (p == t)
    {
      int count=0;
      for(int i=0;i<m;i++)
      {
        if(P[i]!=T[s+i])
        {
          count++;
        }
      }
      if(count==0)
      {
        a_hit[a_count]=s;
        a_count+=1;
      }
      else
      {
        s_hit[s_count]=s;
        s_count+=1;
      }
    }
    if (s < n - m)
    {
      t = (d * (t - T[s] * h) + T[s + m]);
      if(t<0)
      {
        t = q-(abs(t)%q);
      }
    }
  }

  for(int i=0;i<a_count;i++)
  {
     printf("%d ",a_hit[i]);
  }
  printf("\n"); 
  for(int j=0;j<s_count;j++)
  {
    printf("%d ",s_hit[j]);
  }
}
