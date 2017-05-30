#include <iostream>
#include <string>
#include "Enemy.h"
#include "Inventory.h"

using namespace std;

class Doug: public Enemy{

 public:
  Doug();
  ~Doug();
  int talk(Inventory* i);
};
