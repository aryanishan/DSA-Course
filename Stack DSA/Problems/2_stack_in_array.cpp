#include <bits/stdc++.h>
using namespace std;

class Stack{
  public:
  int *arr;
  int size;
  int top1;
  int top2;

  Stack(int size){
    this -> size = size;
    arr = new int[size];
    top1 = -1;
    top2 = size;
  }

  void push1(int data){
    if(top2 - top1 == 1){
      cout<<"Stack Overflow in stack1"<<endl;
    }else{
      top1++;
      arr[top1] = data;
    }
  }

  void pop1(){
    if(top1 == -1){
      cout<<"Stack underflow in stack1"<<endl;
    }else{
      top1--;
    }
  }

  void push2(int data){
    if(top2 - top1 == 1){
      cout<<"Stack Overflow in stack2"<<endl;
    }else{
      top2--;
      arr[top2] = data;
    }
  }

  void pop2(){
    if(top2 == size){
      cout<<"Stack is underflow in stack2"<<endl;
    }else{
      top2++;
    }
  }
};

int main(){
  Stack s(10);

  s.push1(10);
  s.push1(20);
  s.push1(30);
  s.push1(40);
  s.push1(50);

  s.push2(60);
  s.push2(70);
  s.push2(80);
  s.push2(90);

  s.pop1();
  s.pop2();

  cout<<"Top element in stack1 is: "<<s.arr[s.top1]<<endl;
  cout<<"Top element in stack2 is: "<<s.arr[s.top2]<<endl;
  
  return 0;
}