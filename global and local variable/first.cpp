// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

int x = 3;

int main(){
  int x = 44;
  ::x = 55; // changing the variable of global x
  cout<<"The value of x is : "<<x<<endl;
  cout<<"The value of global x is : "<<::x<<endl;

  return 0;
}