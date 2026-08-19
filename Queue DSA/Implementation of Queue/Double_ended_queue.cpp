#include <bits/stdc++.h>
using namespace std;

class Deque{
  public :
  int *arr;
  int size;
  int front;
  int rear;

  Deque(int size){
    this -> size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void pushRear(int val){
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
      cout<<"Queue is already full, can't insert anymore."<<endl;
    }
    else if(front == -1){
      front = 0;
      rear = 0;
      arr[rear] = val;
    }
    else if(front != 0 && rear == size - 1){
      rear = 0;
      arr[rear] = val;
    }
    else {
      rear++;
      arr[rear] = val;
    }

  }

  void popFront(){
    if(front == -1){
      cout<<"Queue is empty."<<endl;
    }
    else if(front == size - 1){
      arr[front] = -1;
      front = 0;
    }
    else if(front == rear){
      arr[front] = -1;
      front = rear = -1;
    }
    else {
      arr[front] = -1;
      front++;
    }
  }

  void pushFront(int val){
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
      cout<<"Queue is full, can't insert anymore."<<endl;
      return ;
    }
    else if(front == -1){
      front = rear = 0;
    }
    else if(front == 0 && rear != size - 1){
      front = size - 1;
    }
    else{
      front--;
    }
    arr[front] = val;
  }

  void popRear(){
    if(front == -1){
      cout<<"Queue is empty."<<endl;
    }
    else if(front == rear){
      arr[front] = -1;
      front = rear = -1;
    }
    else if(rear == 0){
      arr[rear] = -1;
      rear = size - 1;
    }
    else{
      arr[rear] = -1;
      rear--;
    }
  }

  bool isempty(){
    if(front == -1){
      return true;
    }
    return false;
  }

  int getfront(){
    if(front == -1){
      cout<<"Queue is empty"<<endl;
      return -1;
    }else{
      return arr[front];
    }
  }

  int getback(){
    if(front == -1){
      cout<<"Queue is emtpy."<<endl;
      return -1;
    }
    return arr[rear];
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
  Deque dq(10);

  dq.pushFront(23);
  dq.pushRear(43);
  dq.pushFront(432);
  dq.pushRear(52);

  while(!dq.isempty()){
    cout<<dq.getfront()<<endl;
    cout<<dq.getback()<<endl;
    cout<<"Size : "<<dq.getsize()<<endl;
    dq.popRear();
  }

  return 0;

}