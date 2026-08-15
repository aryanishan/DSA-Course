#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this -> data = 0;
    this -> next = NULL;
  }

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }
};

bool checkforloop(Node* &head){
  if(head == NULL){
    return false;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;

    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
      return true;
    }
  }

  return false;
}

Node* startingPoint(Node* &head){
  if(head == NULL){
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;

    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
      slow = head;
      break;
    }
  }

  while(slow != fast){
    slow = slow -> next;
    fast = fast -> next;

  }
  return slow;
}

Node* removeloop(Node* &head){
  if(head == NULL){
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;

    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
      slow = head;
      break;
    }
  }

  Node* prev = fast;

  while(slow != fast){
    prev = fast;
    slow = slow -> next;
    fast = fast -> next;
  }
  prev -> next = NULL;
  return head;
}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
}

int main(){
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);  
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
  Node* sixth = new Node(6);
  Node* seventh = new Node(7);
  Node* eighth = new Node(8);
  Node* ninth = new Node(9);
  Node* tenth = new Node(10);

  head -> next = second;
  second -> next = third; 
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = tenth;
  tenth -> next = fifth;

  cout<<"Loop is present or not : "<<checkforloop(head)<<endl;
  cout<<"Starting point of loop is : "<<startingPoint(head) -> data<<endl;
  head = removeloop(head);
  cout<<"Loop is present or not : "<<checkforloop(head)<<endl;
  print(head);
  return 0;

}