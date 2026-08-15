#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int target){
  if(s.empty()){
    s.push(target);
    return ;
  }

  int data = s.top();
  s.pop();

  solve(s, target);

  s.push(data);
}

void insertAtBottom(stack<int>& s){
  if(s.empty()){
    cout<<"Stack is empty, can't insert the element"<<endl;
  }

  int target = s.top();
  s.pop();

  solve(s, target);
}

int main(){
  stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  insertAtBottom(s);
  cout<<"Printing the elements of the stack : "<<endl;

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}