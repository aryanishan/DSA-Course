#include<bits/stdc++.h>
using namespace std;

class Stack{
  public:
  int *arr;
  int top;
  int size;

  Stack(int size){
    this -> size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int element){
    if(size - top > 1){
      top++;
      arr[top] = element;
    }else{
      cout<<"Stack Overflow"<<endl;
    }
  }

  void pop(){
    if(top == -1){
      cout<<"Stack Underflow, can't delete element from empty stack"<<endl;
    }else{
      top--;
    }
  }

  int gettop(){
    if(top == -1){
      cout<<"Stack is empty, no element present in the stack"<<endl;
      return -1;
    }
      return arr[top];
  }

  int getsize(){
    return top + 1;
  }

  bool isempty(){
    if(top == -1){
      return true;
    }else{
      return false;
    }
  }
};

int main(){
  Stack st(5);

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  st.pop();

  cout<<"Size of the stack is: "<<st.getsize()<<endl;
  cout<<"Top element in the stack is: "<<st.gettop()<<endl;

  while(!st.isempty()){
    cout<<st.gettop()<<" ";
    st.pop();
  }
  cout<<endl;
  cout<<"Now the size of the stack is: "<<st.getsize()<<endl;

  return 0;
}