#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

class HMajor: public Enemy{

 public:
  HMajor();
  ~HMajor();
  int talk();
};
