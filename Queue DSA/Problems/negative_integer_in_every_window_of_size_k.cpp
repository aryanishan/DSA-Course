#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int k){
  deque<int> q;

  for(int i = 0 ; i < k ; i++){
    if(arr[i] < 0){
      q.push_back(i);
    }
  }

  for(int i = k ; i < n ; i++){
    if(q.empty()){
      cout<<0<<" ";
    }else{
      cout<<arr[q.front()]<<" ";
    }

    while((!q.empty())&&(i - q.front() >= k)){
      q.pop_front();
    }

    if(arr[i] < 0){
      q.push_back(i);
    }
  }

  if(q.empty()){
      cout<<0<<" ";
    }else{
      cout<<arr[q.front()]<<" ";
    }
}

int main(){

  int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
  int n = 8;
  int k = 3;

  solve(arr, n, k);
}