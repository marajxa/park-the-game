#include <iostream>
#include <string>
#include "Enemy.h"
#include "Inventory.h"
#include "Key.h"

using namespace std;

class DCooper: public Enemy{

 public:
  DCooper();
  ~DCooper();
  int talk(Inventory* i);
};
