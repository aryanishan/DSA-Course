#include <bits/stdc++.h>
#include "bird.h"
using namespace std;

void birddoes(Bird *&b){
  b->fly();
  b->eat();
}

int main(){
  Bird *b = new Eagle();

  birddoes(b);

  return 0;
}