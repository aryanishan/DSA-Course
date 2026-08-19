#include <bits/stdc++.h>
using namespace std;

void reverseQ(queue<int> &q){
  stack<int> s;

  while(!q.empty()){
    int e = q.front();
    q.pop();

    s.push(e);
  }

  while(!s.empty()){
    int e = s.top();
    s.pop();

    q.push(e);
  }
}

void reverseR(queue<int> &q){
  if(q.empty()){
    return ;
  }

  int e = q.front();
  q.pop();

  reverseR(q);

  q.push(e);
}

int main(){
  queue<int> q;

  q.push(43);
  q.push(4);
  q.push(2);
  q.push(6);
  q.push(8);

  reverseQ(q);
  reverseR(q);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;

  return 0;
}