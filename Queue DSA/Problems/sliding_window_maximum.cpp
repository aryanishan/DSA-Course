#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMax(vector<int>& nums, int k){
  deque<int> dq;
  vector<int> ans;

  for(int i = 0 ; i < k ; i++){
    
    while(!dq.empty() && nums[i] >= nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);

  }
  ans.push_back(nums[dq.front()]);

  for(int i = k ; i < nums.size() ; i++){

    if(!dq.empty()  && i - dq.front() >= k){
      dq.pop_front();
    }

    while(!dq.empty() && nums[i] >= nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);

    ans.push_back(nums[dq.front()]);
  }

  return ans;
}

int main(){
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

  int k = 3;

  vector<int> ans = slidingMax(nums, k);

  for(int i = 0 ; i < ans.size() ; i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}