#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(int gas[], int cost[], int n){
  int balance = 0;
  int deficit = 0;
  int s = 0;

  for(int i = 0 ; i < n ; i++){
    balance += gas[i] - cost[i];

    if(balance < 0){
      deficit += balance;
      s = i + 1;
      balance = 0;
    }


  }

  if(balance + deficit >= 0){
    return s;
  }

  return -1;
}

int main(){
  int gas[5] = {1,2,3,4,5};
  int cost[5] = {3,4,5,1,2};
  int result = canCompleteCircuit(gas, cost, 5);
  if(result != -1){
    cout<<endl<<"Yes, it can complete the circuit. If it start from the index "<<result<<endl;
  }
  else{
    cout<<"Sorry, it can't complete the circuit."<<endl;
  }

  return 0;
}