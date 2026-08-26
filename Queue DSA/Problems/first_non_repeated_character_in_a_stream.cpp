#include <bits/stdc++.h>
using namespace std;

int main(){
  string str = "aabc";

  queue<char> q;
  int freq[26] = {0};
  string result = "";

  for(int i = 0 ; i < str.length() ; i++){
    char ch = str[i];

    freq[ch - 'a']++;
    q.push(ch);

    while(!q.empty()){
      if(freq[q.front() - 'a'] > 1){
        q.pop();
      }
      else{
        result.push_back(q.front());
        break;
      }
    }

    if(q.empty()){
      result.push_back('#');
    }
  }

  cout<<endl<<"The answer is : "<<result<<endl;

  return 0;
}