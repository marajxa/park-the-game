#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

class Haverbro: public Enemy{

 public:
  Haverbro();
  ~Haverbro();
  int talk();
};
