#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q){
  queue<int> q2;
  int n = q.size();
  int k = n/2;
  int count = 0;

  while(!q.empty()){
    int e = q.front();
    q.pop();
    q2.push(e);
    count++;
    if(count == k){
      break;
    }
  }

  while(!q.empty() && !q2.empty()){

    int a = q2.front();
    q2.pop();
    q.push(a);

    int b = q.front();
    q.pop();
    q.push(b);

  }

  if(n&1){
    int e = q.front();
    q.pop();
    q.push(e);
  }
}

int main(){
  queue<int> q;

  q.push(4);
  q.push(8);
  q.push(12);
  q.push(16);
  q.push(20);
  q.push(24);
  // q.push(28);

  interleave(q);

  cout<<"Printing the interleave queue : "<<endl;

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }

  return 0;
}