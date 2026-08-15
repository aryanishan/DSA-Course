#include <bits/stdc++.h>
using namespace std;

int main(){
  stack<char> s;

  string str = "Aryan";

  for(int i = 0 ; i < str.length() ; i++){
    s.push(str[i]);
  }

  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }

return 0;
}