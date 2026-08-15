#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(){
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }

  Node(int data){
    this->data = data;
    this->prev = NULL;
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
  Node* temp = new Node(data);
  if(head == NULL){
    head = tail = temp;
    temp -> next = head;
    temp -> prev = tail;
  }else{
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    tail -> next = head;
    head -> prev = tail;
  }
}

void insertAtTail(Node* &head, Node* &tail, int data){
  Node* temp = new Node(data);
  if(head == NULL){
    head = tail = temp;
    temp -> next = head;
    temp -> prev = tail;
  }else{
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    tail -> next = head;
    head -> prev = tail;
  }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
  if(head == NULL){
    Node* temp = new Node(data);
    head = tail = temp;
    temp -> next = head;
    temp -> prev = tail;
    return ;
  }

  if(position == 1){
    insertAtHead(head, tail, data);
    return;
  }

  int len = getLength(head);
  if(position > len + 1){
    cout<<"Please enter a valid position"<<endl;
    return ;
  }

  if(position == len + 1){
    insertAtTail(head, tail, data);
    return ;
  }

  Node* temp = new Node(data);

  Node* prevnode = head;
  int cnt = 1;
  while(cnt < position - 1){
    prevnode = prevnode -> next;
    cnt++;
  }

  Node* curr = prevnode -> next;
  temp -> next = curr;
  curr -> prev = temp;
  prevnode -> next = temp;
  temp -> prev = prevnode;
}

void deletion(Node* &head, Node* &tail, int position){
  if(head == NULL){
    cout<<"List is empty"<<endl;
    return ;
  }

  if(position == 1){
    Node* temp = head;
    if(head == tail){
      head = tail = NULL;
    }
    else{
      head = head -> next;
    head -> prev = tail;
    tail -> next = head;
    }
    
    delete temp;
    return ;
  }

  int len = getLength(head);

  if(position == len){
    Node* temp = tail;
    tail = tail -> prev;
    tail -> next = head;
    head -> prev = tail;
    delete temp;
    return ;
  }

  if(position > len || position <= 0){
    cout<<"Please enter a valid position"<<endl;
    return ;
  }

  Node* prevnode = head;

  int cnt = 1;
  while(cnt < position - 1){
    prevnode = prevnode -> next;
    cnt++;
  }

  Node* curr = prevnode -> next;

  prevnode -> next = curr -> next;
  curr -> next -> prev = prevnode;
  delete curr;
}

void print(Node* &head){
  Node* temp = head;

  do{
    cout<<temp -> data << " ";
    temp = temp -> next ;
  }while(temp != head);

  cout<<endl;
}

int main(){
  Node* first = new Node (10);
  Node* second = new Node (20);
  Node* third = new Node (30);

  Node* head = first;
  Node* tail = third;

  first -> next = second;
  second -> prev = first;
  second -> next = third;
  third -> prev = second;
  third -> next = head;
  head -> prev = tail;

  print(head);

  insertAtPosition(head, tail, 100, 4);

  print(head);
  cout<<"Head: "<<head -> data <<endl;
  cout<<"Tail: "<<tail -> data <<endl;

  deletion(head, tail, 5);
  print(head);
  cout<<"Head: "<<head -> data <<endl;
  cout<<"Tail: "<<tail -> data <<endl;



  return 0;
}