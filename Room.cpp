/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig and Samantha Kacir
 *
 *Purpose: This program is a game set in Park Science Building. This file is the main file for the Room class.
 */

#include <string>
#include <iostream>
#include "Room.h"

Room::Room(std::string i) {
  name = i;
  reference = NULL;
  north = NULL;
  nLocked = false;
  east = NULL;
  eLocked = false;
  south = NULL;
  sLocked = false;
  west = NULL;
  wLocked = false;
  up = NULL;
  uLocked = false;
  down = NULL;
  dLocked = false; 
  inventory = new Inventory();
}

Room::Room(std::string i, Room* n, Room* e, Room* s, Room* w, Room* u, Room* d) {
    name = i;
    reference = NULL;
    north = n;
    nLocked = false;
    if (north != NULL) {
      north->south = this;
    }
    east = e;
    eLocked = false;
    if (east != NULL) {
      east->west = this;
    }
    south = s;
    sLocked = false;
    if (south != NULL) {
      south->north = this;
    }
    west = w;
    wLocked= false;
    if (west != NULL) {
      west->east = this;
    }
    up = u;
    uLocked = false;
    if (up != NULL) {
      up->down = this;
    }
    down = d;
    dLocked = false;
    if (down != NULL) {
      down->up = this;
    }
    
    inventory = new Inventory();
}

void Room::printOptions() {
  std::cout << "You are in " << name << "." << std::endl;
  if (north != NULL) {
    if (nLocked == true) {
      std::cout << '\t' << "To the north is a locked door labelled " << north->name << std::endl;
    } else {
      std::cout << '\t' << "n: To the north is an unlocked door labelled " << north->name << std::endl;
    }
  }
  if (east != NULL) {
    if (eLocked == true) {
      std::cout << '\t' << "To the east is a locked door labelled " << east->name << std::endl;
    } else {
      std::cout << '\t' << "e: To the east is an unlocked door labelled " << east->name << std::endl;
    }
  }
  if (south != NULL) {
    if (sLocked == true) {
      std::cout << '\t' << "To the south is a locked door labelled " << south->name << std::endl;
    } else {
      std::cout << '\t' << "s: To the south is an unlocked door labelled " << south->name << std::endl;
    }
  }
  if (west != NULL) {
    if (wLocked == true) {
      std::cout << '\t' << "To the west is a locked door  labelled " << west->name << std::endl;
    } else {
      std::cout << '\t' << "w: To the west is an unlocked door labelled " << west->name << std::endl;
    }
  }
  if (up != NULL) {
    if (uLocked == true) {
      std::cout << '\t' << "There is a locked staircase labelled " << up->name << std::endl;
    } else {
      std::cout << '\t' << "u: There is an unlocked staircase labelled " << up->name << std::endl;
    }
  }
  if (down != NULL) {
    if (dLocked == true) {
      std::cout << '\t' << "There is a locked trapdoor labelled " << down->name << std::endl;
    } else {
      std::cout << '\t' << "d: There is an unlocked trapdoor labelled " << down->name << std::endl;
    }
  }
}

Room* Room::moveNorth() {
  if (nLocked ==false) {
    return this->north;
  } else if (north == NULL) {
    std::cout << "There's no door there, silly!" << std::endl;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}

Room* Room::moveEast() {
  if (eLocked ==false) {
    return this->east;
  } else if (east == NULL) {
    std::cout << "There's no door there, silly!" << std::endl;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}

Room* Room::moveSouth() {
  if (sLocked ==false) {
    return this->south;
  } else if (south == NULL) {
    std::cout << "There's no door there, silly!" << std::endl;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}

Room* Room::moveWest() {
  if (wLocked ==false) {
    return this->west;
  } else if (west == NULL) {
    std::cout << "There's no door there, silly!" << std::endl;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}

Room* Room::moveUp() {
  if (uLocked ==false) {
    return this->up;
  } else if (up == NULL) {
    std::cout << "There's no staircase there, silly!" << std::cout;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}
 
Room* Room::moveDown() {
  if (dLocked ==false) {
    return this->down;
  } else if (down == NULL) {
    std::cout << "There's no trapdoor there, silly!" << std::cout;
    return this;
  } else {
    std::cout << "Oops! That room is locked!" << std::endl;
    return this;
  }
}

void Room::nLock() {
  nLocked = true;
  north->sLocked = true;
}

void Room::eLock() {
  eLocked = true;
  east->wLocked = true;
}

void Room::sLock() {
  sLocked = true;
  south->nLocked = true;
}

void Room::wLock() {
  wLocked = true;
  west->eLocked = true;
}

void Room::uLock() {
  uLocked = true;
  up->dLocked = true;
}

void Room::dLock() {
  dLocked = true;
  down->uLocked = true;
}

void Room::nUnlock() {
  nLocked = false;
  north->sLocked = false;
}

void Room::eUnlock() {
  eLocked = false;
  east->wLocked = false;
}

void Room::sUnlock() {
  sLocked = false;
  south->nLocked = false;
}

void Room::wUnlock() {
  wLocked = false;
  west->eLocked = false;
}

void Room::uUnlock() {
  uLocked = false;
  up->dLocked = false;
}

void Room::dUnlock() {
  dLocked = false;
  down->uLocked = false;
}

bool Room::isNorth() {
  if (north != NULL) {
    return true;
  } 
  return false;
}
bool Room::isEast() {
  if (east != NULL) {
    return true;
  }
  return false;
}
bool Room::isSouth() {
  if (south != NULL) {
    return true;
  }
  return false;
}
bool Room::isWest() {
  if (west != NULL) {
    return true;
  }
  return false;
}
bool Room::isUp() {
  if (up != NULL) {
    return true;
  } 
  return false;
}
bool Room::isDown() {
  if (down != NULL) {
    return true;
  }
  return false;
}

//Sam's
int Room::neighbor(Room* r){
  if(north != NULL && north==r){
    return NORTH;
  }
  if(west != NULL && west==r){
    return WEST;
  }
  if(south != NULL && south==r){
    return SOUTH;
  }
  if(east != NULL && east==r){
    return EAST;
  }
  if(up != NULL && up==r){
    return UP;
  }
  if(down != NULL && down==r){
    return DOWN;
  }
  else{
    return 0;
  }
}

Room* Room::move(Room::directions d){
  if(d == NORTH){
    return moveNorth();
  }
  else if(d == EAST){
    return moveEast();
  }
  else if(d == SOUTH){
    return moveSouth();
  }
  else if(d == WEST){
    return moveWest();
  }
  else if(d == UP){
    return moveUp();
  }
  else if(d == DOWN){
    return moveDown();
  }
  return this;
}

std::string Room::getName(){
  return name;
}

void Room::unlockAll(){
  if(north != NULL && nLocked){
    //std::cout << "n" << std::endl;
    nUnlock();
    north->unlockAll();
  }
  if(east != NULL && eLocked){
    //std::cout << "e" << std::endl;
    eUnlock();
    east->unlockAll();
  }
  if(south != NULL && sLocked){
    //std::cout << "s" << std::endl;
    sUnlock();
    south->unlockAll();
  }
  if(west != NULL && wLocked){
    //std::cout << "w" << std::endl;
    wUnlock();
    west->unlockAll();
  }
  if(up != NULL && uLocked){
    //std::cout << "u" << std::endl;
    uUnlock();
    up->unlockAll();
  }
  if(down != NULL && dLocked){
      //std::cout << "d" << std::endl;
      dUnlock();
      down->unlockAll();
  }

  return;
  
}

bool Room::isEnemy() {
  if (enemy != NULL) {
    return true;
  }
  return false;
}

bool Room::isEmpty() {
  if (inventory->sizeOfI() == 0) {
    return true;
  }
  return false;
}

void Room::setRef(int* ref) {
  reference = ref;
}

int* Room::getRef() {
  return reference;
}
