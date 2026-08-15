#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    data = 0;
    next = NULL;
  }

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }

  ~Node(){
    if(next != NULL){
      delete next;
      next = NULL;
    }

    cout<<"Memory has been freed from data: "<<data<<endl;
  }
};

class Stack{
  public:
  Stack* top;


};

int main(){

  return 0;
}