#include <bits/stdc++.h>
using namespace std;

class CirQueue{

  public:
  int size;
  int *arr;
  int front;
  int rear;

  CirQueue(int size){
    this -> size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int data){
    if((front == 0 && rear == size - 1) || (front == rear + 1)){ // (rear == (front - 1) % (sizes - 1)) This condition can also be used.
      cout<<"Queue is full."<<endl;
    }
    else if(front == -1){
      front = 0;
      rear = 0;
      arr[rear] = data;
    }
    else if(rear == size -1 && front != 0){
      rear = 0;
      arr[rear] = data;
    }
    else{
      rear++;
      arr[rear] = data;
    }
  }

  void pop(){
    if(front == -1){
      cout<<"Queue is empty."<<endl;
    }
    else if(front == rear){
      arr[front] = -1;
      front = rear = -1;
    }
    else if(front == size - 1){
      front = 0;
    }
    else{
      front++;
    }
  }

  bool isempty(){
    if(front == -1){
      return true;
    }
    else{
      return false;
    }
  }

  int getfront(){
    if(front == -1){
      cout<<"Queue is empty"<<endl;
      return -1;
    }
    else{
      return arr[front];
    }
  }

  int getsize(){
    if(front == -1){
      return 0;
    }
    else if(rear >= front){
      return rear - front + 1;
    }
    return size - front + rear + 1;
  }
};

int main(){
  CirQueue q(10);

  q.push(13);
  q.push(44);

  cout<<"Size of circular queue is : "<<q.getsize()<<endl;

  q.pop();

  cout<<"Size of circular queue is : "<<q.getsize()<<endl;

  cout<<"Front element of queue is : "<<q.getfront()<<endl;

  q.isempty() ? cout<<"Cicular queue is empty" : cout<<"Cicular queue is not empty" ;

  return 0;
}