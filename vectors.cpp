#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v;
  v.push_back(1);
  v.emplace_back(2);

  vector<pair<int, int>> vec;
  vec.push_back({1,2});
  vec.emplace_back(1,2);

  vector<int>{5,100}; // container with size 5 with 5 values of 100 is created.

  vector<int> v1{5}; // container with size 5 with 5 values of 0 is created.
  vector<int> v2(v1);
  for(int i=0;i<sizeof(vec);i++)
  {
    cout<<vec[i]<<"\n";
  }

}