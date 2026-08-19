#include <bits/stdc++.h>
using namespace std;

void reverseKelements(queue<int> &q, int k){
  if(k <= 0 || k > q.size()){
    return ;
  }
  stack<int> s;
  int n = q.size();
  int count = 0;

  while(!q.empty()){
    int e = q.front();
    q.pop();

    s.push(e);
    count++;
    if(count == k){
      break;
    }

  }

  while(!s.empty()){
    int e = s.top();
    s.pop();

    q.push(e);
  }

  count = 0;

  while(!q.empty() && n-k != 0){
    int e = q.front();
    q.pop();

    q.push(e);
    count++;
    if(count == n - k){
      break;
    }
  }


}

int main(){
  queue<int> q;

  q.push(3);
  q.push(5);
  q.push(7);
  q.push(8);
  q.push(2);


  reverseKelements(q, 5);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }


  return 0;
}