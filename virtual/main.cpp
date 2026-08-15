#include <bits/stdc++.h>
using namespace std;

class Base{
  public:

  Base(){
    cout<<"Base Ctor"<<endl;
  }

  virtual ~Base(){
    cout<<"Base Dtor"<<endl;
  }
};

class Derived: public Base{
  public:

  Derived(){
    cout<<"Derived Ctor"<<endl;
  }

  ~Derived(){
    cout<<"Derived Dtor"<<endl;
  }
};

int main(){
  Base *b = new Derived();
  delete b;
  return 0;
}