#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

vector<int> prevsmaller(vector<int> v){
  int n = v.size();
  stack<int> s; 
  s.push(-1);

  vector<int> ans(n);

  for(int i = 0 ; i < n ; i++){
    int curr = v[i];
    while(s.top() != -1 && v[s.top()] >= curr){
      s.pop();
    }

    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

vector<int> nextsmaller(vector<int> v){
  int n = v.size();
  stack<int> s;
  s.push(-1);

  vector<int> ans(n);

  for(int i = n - 1 ; i >= 0 ; i--){
    int curr = v[i];

    while(s.top() != -1 && v[s.top()] >= curr){
      s.pop();
    }

    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

int greaterArea(vector<int> &height){
  int n = height.size();

  vector<int> next = nextsmaller(height);
  vector<int> prev = prevsmaller(height);

  int maxarea = INT_MIN;

  for(int i = 0 ; i < n ; i++){
    int len = height[i];

    if(next[i] == -1){
      next[i] = n;
    }

    int width = next[i] - prev[i] - 1;
    int area = len * width;

    maxarea = max(maxarea, area);
  }

  return maxarea;
}

int main(){
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(6);
  v.push_back(6);
  v.push_back(2);
  v.push_back(3);

  cout<<"Largest area is : "<<greaterArea(v)<<endl;

  return 0;
}