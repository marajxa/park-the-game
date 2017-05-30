/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is for non-class functions written by Sophie Rehrig.
 */

#include <iostream>
#include <string>
#include "functions.h"
#include "Room.h"
#include "Item.h"

void useKey(Room* room, Key* key) {
  bool didSomething = false;
  if (room->getRef() == key->getRef()) {
    int* keyhole = room->getRef();
    if (*keyhole == 1 && room->isNorth()) {
      room->nUnlock();
      didSomething = true;
    } else if (*keyhole == 2 && room->isEast()) {
      room->eUnlock();
      didSomething = true;
    } else if (*keyhole == 3 && room->isSouth()) {
      room->sUnlock();
      didSomething = true;
    } else if (*keyhole == 4 && room->isWest()) {
      room->wUnlock();
      didSomething = true;
    } else if (*keyhole == 5 && room->isUp()) {
      room->uUnlock();
      didSomething = true;
    } else if (*keyhole == 6 && room->isDown()) {
      room->dUnlock();
      didSomething = true;
    }
  }
  if (!didSomething) {
    std::cout << "Nothing was unlocked!" << std::endl;
  }
}
