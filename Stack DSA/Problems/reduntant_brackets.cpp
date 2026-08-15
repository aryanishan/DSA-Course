#include <bits/stdc++.h>
using namespace std;

bool redun(stack<char>& s, string str){
  for(int i = 0; i < str.length() ; i++){
    char ch = str[i];
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
      s.push(ch);
    }else if(ch == ')'){
      bool hasOperator = false;

      while(!s.empty() && s.top() != '('){
        char top = s.top();

        if(top == '+' || top == '-' || top == '*' || top == '/'){
          hasOperator = true;
        }

        s.pop();
      }

      if(!hasOperator){
        return true;
      }

      if(!s.empty()){
        s.pop();
      }
    }
  }

  return false;
}

int main(){
  stack<char> s;

  string str = "(a+b))";

  if(redun(s, str)){
    cout<<"There are some reduntant brackets in the expression."<<endl;
  }else{
    cout<<"There is no reduntant brackets in the expression."<<endl;
  }

  return 0;

}