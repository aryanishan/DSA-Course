#include <bits/stdc++.h>
using namespace std;

int main(){
  queue<int> q;

  q.push(32);
  q.push(43);
  q.push(55);
  q.push(4);

  cout<<"Size of the queue is : "<<q.size()<<endl;
  q.pop();
  cout<<"Now after removing one element, the size of the queue is : "<<q.size()<<endl;

  return 0;
}