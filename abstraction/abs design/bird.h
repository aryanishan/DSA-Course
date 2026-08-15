#if !defined(BIRD_H)
#define BIRD_H

#include <bits/stdc++.h>
using namespace std;

class Bird{
  public:
  virtual void fly() = 0;
  virtual void eat() = 0;
};

class Sparrow : public Bird{
  public:
  void eat(){
    cout<<"Bird is eating"<<endl;
  }

  void fly(){
    cout<<"Bird is flying"<<endl;
  }
};

class Eagle : public Bird{
  public:
  void eat(){
    cout<<"Eagle is eating"<<endl;
  }

  void fly(){
    cout<<"Eagle is flying"<<endl;
  }

};

#endif