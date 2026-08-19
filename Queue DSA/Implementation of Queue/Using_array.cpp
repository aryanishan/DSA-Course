#include <bits/stdc++.h>
using namespace std;

class Queue{
  public:
  int* arr;
  int size;
  int front;
  int rear;

  Queue(int size){
    this -> size = size;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void push(int data){
    if(rear == size){
      cout<<"Queue is full"<<endl;
    }else{
      arr[rear] = data;
      rear++;
    }
  }

  void pop(){
    if(front == rear){
      cout<<"Queue is empty"<<endl;
    }else{
      arr[front] = -1;
      front++;

      if(front == rear){
        front = 0;
        rear = 0;
      }
    }
  }

  int getfront(){
    if(front == rear){
      cout<<"Queue is empty"<<endl;
      return -1;
    }else{
      return arr[front];
    }
  }

  bool isempty(){
    if(front == rear){
      return true;
    }else{
      return false;
    }
  }

  int getsize(){
    return rear - front;
  }
};

int main(){
  Queue q(10);

  q.push(23);
  q.push(44);
  q.push(22);
  q.push(87);

  cout<<"Size of queue is : "<<q.getsize()<<endl;

  q.pop();

  cout<<"Now size of queue is : "<<q.getsize()<<endl;

  cout<<"Front element of queue is : "<<q.getfront()<<endl;

  q.isempty() ? cout<<"Queue is empty" : cout<<"Queue is not empty";
  return 0;
}