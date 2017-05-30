#include <iostream>
#include <string>
#include "Enemy.h"
#include "Inventory.h"

using namespace std;

class DXu: public Enemy{

 public:
  DXu();
  ~DXu();
  int talk(Inventory* i);
};
