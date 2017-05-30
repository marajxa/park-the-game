#include <iostream>
#include <string>
#include "Enemy.h"
#include "inventory.h"

using namespace std;

class DXu: public Enemy{

 public:
  DXu();
  ~DXu();
  int talk(Inventory* i);
};
