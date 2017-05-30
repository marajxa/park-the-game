#include "Enemy.h"


void Enemy::get_name(){
      cout << name << endl;
      //return name;
    }


void Enemy::check(){
  if(!dead){
  cout << name << ": " << endl;
  cout << des << endl;
  } else {
    cout << "They will no longer talk to you" << endl;
  }
}

Enemy::Enemy(){

}

Enemy::~Enemy(){

}

bool Enemy::kill(){
 dead = true;
}

int Enemy::talk(Inventory* i) {
  return i->sizeOfI();
}

