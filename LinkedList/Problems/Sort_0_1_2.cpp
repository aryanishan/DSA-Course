#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data ;
  Node* next;

  Node(){
    this -> data = 0;
    this -> next = NULL;
  }

  Node(int data) {
    this -> data = data;
    this -> next = NULL;
  }

  ~Node() {
    if(this -> next != NULL){
      delete next;
      this -> next = NULL;
    }

    cout<<"Memory is free for node with data: "<<this -> data<<endl;
  }
};


// Method 1 ------ By replacing the numbers
// Node* sort1(Node* &head){
//   if(head == NULL){
//     return head;
//   }

//   Node* temp = head;
//   int count0 = 0;
//   int count1 = 0;
//   int count2 = 0;
//   while(temp != NULL){
//     if(temp -> data == 0){
//       count0++;
//       temp = temp -> next;
//     }
//     else if(temp -> data == 1){
//       count1++;
//       temp = temp -> next;
//     }
//     else if(temp -> data == 2){
//       count2++;
//       temp = temp -> next;
//     }
//   }

//   temp = head;

//   while(count0--){
//     temp -> data = 0;
//     temp = temp -> next;
//   }

//   while(count1--){
//     temp -> data = 1;
//     temp = temp -> next;
//   }

//   while(count2--){
//     temp -> data = 2;
//     temp = temp -> next;
//   }

//   return head;
// }

// Method 2 --------
Node* sort2(Node* &head){
  if(head == NULL){
    return head;
  }

  Node* zerohead = new Node(-1);
  Node* zerotail = zerohead;
  Node* onehead = new Node(-1);
  Node* onetail = onehead;
  Node* twohead = new Node(-1);
  Node* twotail = twohead;


  Node* curr = head;

  while(curr != NULL){
    if(curr -> data == 0){
      Node* temp = curr;
      curr = curr -> next;
      temp -> next = NULL;

      zerotail -> next = temp;
      zerotail = temp;
    }
    else if(curr -> data == 1){
      Node* temp = curr;
      curr = curr -> next;
      temp -> next = NULL;

      onetail -> next = temp;
      onetail = temp;
    }
    else if(curr -> data == 2){
      Node* temp = curr;
      curr = curr -> next ;
      temp -> next = NULL;

      twotail -> next = temp;
      twotail = temp;
    }
  }

  Node* one1 = onehead;
  onehead = onehead -> next;
  one1 -> next = NULL;
  delete one1;

  Node* two1 = twohead;
  twohead = twohead -> next;
  two1 -> next = NULL;
  delete two1;


  // zerotail -> next = onehead;
  // onetail -> next = twohead;

  if(onehead != NULL){
    zerotail -> next = onehead;
    if(twohead != NULL){
      onetail -> next = twohead;
    }
  }else{
    if(twohead != NULL){
      zerotail -> next = twohead;
    }
  }

  Node* zero1 = zerohead;
  zerohead = zerohead -> next;
  zero1 -> next = NULL;
  delete zero1;
  
  return zerohead;

}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
  cout<<endl;
}

int main(){
  Node* head = new Node(1);
  Node* second = new Node(0);
  Node* third = new Node(1);
  Node* fourth = new Node(2);
  Node* fifth = new Node(1);
  Node* sixth = new Node(0);

  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = NULL;

  print(head);

  cout<<"After sorting: "<<endl;
  // head = sort1(head);
  head = sort2(head);
  print(head);
  return 0;
}