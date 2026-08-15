#include <bits/stdc++.h>
using namespace std;

bool valid(string s){
  stack<char> st;

  for(int i = 0 ; i < s.length() ; i++){
    char ch = s[i];

    
    if(ch == '(' || ch == '{' || ch == '['){
      st.push(ch);
    }else{
      if(!st.empty()){
        char topelement = st.top();

        if(ch == ')' && topelement == '('){
          st.pop();
        }
        else if(ch == '}' && topelement == '{'){
          st.pop();
        }
        else if(ch == ']' && topelement == '['){
          st.pop();
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
  }

  if(st.empty()){
    return true;
  }

  return false;
}

int main(){
  string str = "({)}";

  if(valid(str)){
    cout<<"This is a valid parenthesis."<<endl;
  }else{
    cout<<"This is not a valid parenthesis."<<endl;
  }

  return 0;
}