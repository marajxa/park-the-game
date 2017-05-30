#ifndef buddy
#define buddy

#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

class Enemy {

  
 public:
  Enemy();
  ~Enemy();

  string name;
  string des;
  bool dead;
  void get_name();
  void check();
  bool kill();
  Inventory* inventory;
  virtual int talk(Inventory* i); //Sophie added this for compilation
  //type system for description?
};

#endif
