#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this->data = 0;
    this->next = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
  }

  ~Node(){
    int value = this -> data;
    if(this -> next != NULL){
      delete next;
      this -> next = NULL;
    }

    cout<<"Memory is free for node with data "<<value <<endl;
  }
};

int getLength(Node* &head){
  int len = 0;
  Node* temp = head;

  do{
    len++;
    temp = temp -> next;
  }while(temp != head);

  return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
    temp -> next = head;
    return ;
  }

  Node* temp = new Node(data);
  temp -> next = head;
  head = temp;
  tail -> next = head;
}

void insertAtTail(Node* &head, Node* &tail, int data){
  Node* temp = new Node(data);
  if(head == NULL){
    head = temp;
    tail = temp;
    temp -> next = head;
  }else{
    tail -> next = temp;
    tail = temp;
    tail -> next = head;
  }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
  if(head == NULL){
    Node* temp = new Node(data);
    head = tail = temp;
    temp -> next = head;
    return ;
  }
  if(position == 1){
      insertAtHead(head, tail, data);
      return ;
  }

  int len = getLength(head);

  if(position == len + 1){
    insertAtTail(head, tail, data);
    return ;
  }

  if(position > len + 1){
    cout<<"Please enter a valid position"<<endl;
    return ;
  }


  Node* temp = new Node(data);

    Node* prevnode = head;
    int cnt = 1;
    while(cnt < position - 1 ){
      prevnode = prevnode -> next;
      cnt++;
    }

    Node* curr = prevnode -> next;
    prevnode -> next = temp;
    temp -> next = curr;
  
}

void deletion(Node* &head, Node* &tail, int position){
  if(head == NULL){
    cout<<"List is empty"<<endl;
    return ;
  }

  int len = getLength(head);
    if(position > len || position <= 0){
      cout<<"Please enter a valid position"<<endl;
      return ;
    }

  if(head == tail){
    delete head;
    head = tail = NULL;
    return ;
  }

  if(position == 1){
    Node* temp = head;
    head = head -> next;
    tail -> next = head;
    delete temp ;
    return ;
  }

  Node* prevnode = head;
  int cnt = 1;
  while(cnt < position - 1){
    prevnode = prevnode -> next;
    cnt++;
  }

  Node* curr = prevnode -> next;

  if(curr == tail){
    prevnode -> next = head;
    tail = prevnode;
    delete curr;
  }else{
    prevnode -> next = curr -> next;
    delete curr;
  }
}

void print(Node* &head){
  if(head == NULL){
    cout<<"List is empty"<<endl;
    return ;
  }

  Node* temp = head;

  do{
    cout<<temp -> data << " ";
    temp = temp -> next ;
  }while(temp != head);

  cout<<endl;
}

int main(){
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* head = first;
  Node* tail = third;

  first->next = second;
  second->next = third;
  third->next = first;

  print(head);

  insertAtHead(head, tail, 5);
  print(head);

  insertAtTail(head, tail, 40);
  print(head);

  insertAtPosition(head, tail, 25, 4);
  print(head);

  deletion(head, tail, 1);
  print(head);

  deletion(head, tail, 6);
  print(head);

  deletion(head, tail, 4);
  print(head);

  cout<<"Head: "<<head -> data <<endl;
  cout<<"Tail: "<<tail -> data <<endl;

  return 0;
}