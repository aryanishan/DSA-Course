#include<bits/stdc++.h>
using namespace std;

int valid(string s){
  stack<int> st;
  st.push(-1);

  int maxlen = 0;

  for(int i = 0 ; i < s.length() ; i++){
    char ch = s[i];

    if(ch == '('){
      st.push(i);
    }else{
      st.pop();

      if(st.empty()){
        st.push(i);
      }else{
        int len = i - st.top();
        maxlen = max(len, maxlen);
      }
    }
  }
  return maxlen;
}

int main(){
  string s;

  cout<<"Enter the parenthesis string : ";
  cin>>s;

  cout<<"Length of longest valid parenthesis is : "<<valid(s)<<endl;
  return 0;
}