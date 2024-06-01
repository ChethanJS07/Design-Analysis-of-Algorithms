#include<bits/stdc++.h>
using namespace std;

int power(int base,int exp)
{
  int result=1;
  while(exp!=0)
  {
    if(exp%2!=0)
    {
      result*=base;
    }
    base*=base;
    exp/=2;
  }
  return result;
}
int karat(int x,int y,int n)
{
  if(n==1)
  {
    return x*y;
  }
  else
  {
    int half = n/2;
    int a = x / power(10, half);
    int b = x % (int)power(10, half);
    int c = y / power(10, half);
    int d = y % (int)power(10, half);


    int ac=karat(a,c,half);
    int bd=karat(b,d,half);
    int extra=karat(a+b,c+d,half)-ac-bd;
    return (power(10,n)*ac+power(10,half)*extra+bd);
  }
}
int main()
{
  int x,y;
  cin>>x;
  cin>>y;
  int temp=x,count=0;
  while(temp>0)
  {
    count+=1;
    temp=temp/10;
  }
  int result = karat(x,y,count);
  cout<<"The product of "<<x<<" and "<<y<<" is : "<<result;
}