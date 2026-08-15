#include <bits/stdc++.h>
using namespace std;

int main(){
  stack<int> st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  st.pop();

  cout<<"Top element in the stack is: "<<st.top()<<endl;

  cout<<"Size of the stack is: "<<st.size()<<endl;

  if(st.empty()){
    cout<<"Stack is empty"<<endl;
  }else{
    cout<<"Stack is not empty"<<endl;
  }

  return 0;
}