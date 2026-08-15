#include <bits/stdc++.h>
using namespace std;

class Box {
  int weight;
  Box(int val): weight(val) {}

  public:
  int getWeight() const {
    return weight;
  }

  void setWeight(int v){
    weight = v;
  }

  friend class BoxPresenter;

};

class BoxPresenter{
  int count;

  public :
  Box getAbox (int val) {
    ++count;
    return Box(val);
  }
};

int main(){
  BoxPresenter b1;
  Box b = b1.getAbox(5);

  cout<<b.getWeight()<<endl;

  return 0;
}