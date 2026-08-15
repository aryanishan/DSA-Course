#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v = { 23, 4 ,12,1};
  sort(v.begin(), v.end());

  for(auto i : v){
    cout<<i<<" ";
  }

  return 0;
}