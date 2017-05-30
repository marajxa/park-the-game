/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig and Samantha Kacir
 *
 *Purpose: This program is a game set in Park Science Building. This file is the header file for the Room class.
 */

#ifndef Room_H
#define Room_H

#include <string>
#include "Inventory.h"
#include "Enemy.h"

class Room {
  std::string name; //the name the player will see
  int* reference; //the linking point for the Key: see Key.h
  Room* north; //the pointer to the room north of this, NULL if there isn't one, the same for the other directions below
  bool nLocked; //if the door to the room to the north is unlocked, the same for the other directions below
  Room* east;
  bool eLocked;
  Room* south;
  bool sLocked;
  Room* west;
  bool wLocked;
  Room* up;
  bool uLocked;
  Room* down;
  bool dLocked;
 public:
  Inventory* inventory; //this is where objects in the room are stored
  Enemy* enemy; //this could be NULL. there's max one enemy per room
  Room(std::string i); //the first room doesn't need to be linked to other rooms
  Room(std::string i, Room* n, Room* e, Room* s, Room* w, Room* u, Room* d); //if some of these linking spots are unoccupied, use NULL
  void printOptions(); //this prints out the rooms that lead off from this one, and if they are locked or unlocked
  void setRef(int* ref); //this sets the link between a Room and a Key. ref must be the same pointer as the Key constructor took
  int* getRef(); //gets the ref pointer associated with the room, if there is one
  bool isEnemy(); //true if there is an enemy inside
  bool isEmpty(); //true if the room's inventory is empty
  Room* moveNorth(); //returns the room the player ends this action on (the north one if the move was successful, the current one if not)
  Room* moveEast();
  Room* moveSouth();
  Room* moveWest();
  Room* moveUp();
  Room* moveDown();
  void nLock(); //locks the door to the north
  void eLock();
  void sLock();
  void wLock();
  void uLock();
  void dLock();
  void nUnlock(); //unlocks the door to the north
  void eUnlock();
  void sUnlock();
  void wUnlock();
  void uUnlock();
  void dUnlock();
  bool isNorth(); //true if north is not NULL
  bool isEast();
  bool isSouth();
  bool isWest();
  bool isUp();
  bool isDown();
  //Sam's
  enum directions{
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4,
    UP = 5,
    DOWN = 6
  };
  int neighbor(Room* r);
  Room* move(directions d);
  std::string getName();
  void unlockAll();
};

void buildPark(Room** ret);

#endif
