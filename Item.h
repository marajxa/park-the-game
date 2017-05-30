/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is a header file for the Item class.
 */

#ifndef Item_H
#define Item_H

#include <string>
#include "Object.h"

class Item : public Object{
  int hm; //how much motivation this thing takes or gives (positive for gives, negative for takes)
 public:
  Item(std::string hn, std::string hd, bool hh, int hm);
  void printItem();
  int getMotivation(); //returns hm
};

#endif
