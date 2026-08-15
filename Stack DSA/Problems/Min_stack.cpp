#include <bits/stdc++.h>
using namespace std;

class Minstack {
  public :
  vector<pair<int, int>> st;
  Minstack(){

  }

  void push(int val){
    if(st.empty()){
      pair<int, int> p = make_pair(val, val);
      st.push_back(p);
    }else{
      pair<int, int> p = make_pair(val, min(val, st.back().second));
      st.push_back(p);
    }
  }

  void pop(){
    st.pop_back();
  }

  int top(){
    return st.back().first;
  }

  int getMin(){
    return st.back().second;
  }
};

int main(){
  Minstack s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  s.pop();
  cout<<s.getMin()<<endl;
  cout<<s.top()<<endl;

  return 0;
}