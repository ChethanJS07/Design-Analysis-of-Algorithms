#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin>>a;
	int sum=0;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			sum+=i;
			if((a/i)!=i)
			{
				sum+=(a/i);
			}
		}
	}
	cout<<sum<<endl; 
}