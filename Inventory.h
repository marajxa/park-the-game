/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the header file for the Inventory class.
 */

#ifndef Inventory_H
#define Inventory_H

#include "Item.h"
#include "Key.h"
#include "Object.h"

class Inventory {
  Object* data; //current Object in the slot
  Inventory* next; //next slot in the inventory
  int size; //how many Objects are inside
  int type; //0 for item and 1 for key
 public:
  Inventory(); //Inventories start off empty when they are first created
  ~Inventory();
  int sizeOfI(); //returns size of inventory
  void printHold(); //prints out the contents of the inventory
  void add(Item* i); //add an Item
  void add(Key* k); //add a Key
  Inventory* remove(Item* i); //remove an Item
  Inventory* remove(Key* k); //remove a Key
  bool isEmpty(); //true if there are no Objects in the Inventory
  Object* getFromPos(int pos); //takes a position in the inventory and returns the Object there, skipping over Hidden Objects
  int pain(); //test method
  bool hasVisible(); //if the inventory contains any visible items
};

#endif
