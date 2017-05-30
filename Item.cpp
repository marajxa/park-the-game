/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the main file for the Item class.
 */

#include "Item.h"
#include "Object.h"
#include <string>
#include <iostream>


Item::Item(std::string n, std::string d, bool h, int m): Object(n, d, h){
  hn = n;
  hd =d;
  hh = h;
  hm = m;
  hi = true;
}

int Item::getMotivation() {
  return hm;
}

void Item::printItem() {
  std::cout << "Item: " << hn << "\n" << hd << std::endl;
}

