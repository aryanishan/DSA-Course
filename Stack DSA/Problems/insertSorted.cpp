// If stack is sorted only then this code will work --

#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& st, int target){
  if(st.empty()){
    st.push(target);
    return ;
  }

  if(st.top() >= target){
    st.push(target);
    return ;
  }

  int topelement = st.top();
  st.pop();

  insertSorted(st, target);

  st.push(topelement);
}

int main(){
  stack<int> st;

  st.push(11);
  st.push(8);
  st.push(5);
  st.push(2);

  int target = 6;

  insertSorted(st, target);

  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }

  return 0;
}