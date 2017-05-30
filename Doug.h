#include <iostream>
#include <string>
#include "Enemy.h"
#include "inventory.h"

using namespace std;

class Doug: public Enemy{

 public:
  Doug();
  ~Doug();
  int talk(Inventory* i);
};
