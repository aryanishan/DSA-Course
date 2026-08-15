#include <bits/stdc++.h>
using namespace std;

void insertATBottom(stack<int>& s, int target){
  if(s.empty()){
    s.push(target);
    return ;
  }

  int data = s.top();
  s.pop();

  insertATBottom(s, target);

  s.push(data);
}

void reversestack(stack<int>& s){
  
  if(s.empty()){
    return ;
  }

  int target = s.top();
  s.pop();

  reversestack(s);

  insertATBottom(s, target);
}

int main(){
  stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);

  reversestack(s);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}