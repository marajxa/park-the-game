#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

class Frosh: public Enemy{

 public:
  Frosh();
  ~Frosh();
  int talk();
};
