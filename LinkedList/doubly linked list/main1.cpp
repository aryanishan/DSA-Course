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
    int value = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }
    cout<<"Memory is free for node with data "<<value<<endl;
  }
};

int getLength(Node* &head){
  int len = 0;
  Node* temp = head;

  while(temp != NULL){
    len++;
    temp = temp->next;
  }

  return len;
}

void insertAtTail(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
  }else{
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtHead(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
  }else{
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
  }else{
    if(position == 1){
      insertAtHead(head, tail, data);
      return ;
    }

    int len = getLength(head);
    if(position > len){
      insertAtTail(head, tail, data);
      return ;
    }
    Node* prevnode = head;
    int cnt = 1;
    while(cnt < position - 1){
      prevnode = prevnode -> next;
      cnt++;
    }

    Node* curr = prevnode -> next;
    Node* temp = new Node(data);

    prevnode -> next = temp;
    temp -> prev = prevnode;
    temp -> next = curr;
    curr -> prev = temp;


  }
}

void deletion(Node* &head, Node* &tail, int position){
  if(head == NULL){
    cout<<"List is empty"<<endl;
    return ;
  }

  if(head -> next == NULL){
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp ;
    return;
  }

  int len = getLength(head);

  if(position > len){
    cout<<"Please enter a valid position"<<endl;
    return ;
  }

  if(position == 1){
    Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    temp -> next = NULL;
    delete temp;
    return ;
  }

  if(position == len){
    Node* temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    temp -> prev = NULL;
    delete temp;
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
  curr -> next = NULL;
  curr -> prev = NULL;
  delete curr;

}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* head = first;
  Node* tail = third;
  first->next = second;
  second->prev = first;

  second->next = third;
  third->prev = second;

  insertAtHead(head, tail, 110);

  // print(head);

  // print(first);

  insertAtPosition(head, tail, 6, 120);
  // cout<<"head: "<<head->data<<endl;
  // cout<<"tail: "<<tail->data<<endl;
  print(head);

  deletion(head, tail, 6);
  cout<<"head: "<<head -> data <<endl;
  cout<<"tail: "<<tail -> data <<endl;

  print(head);
  return 0;
}