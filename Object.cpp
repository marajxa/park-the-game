/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the main file for the Object class.
 */

#include "Object.h"
#include <string>
#include <iostream>

Object::Object(std::string n, std::string d, bool h) {
  hn = n;
  hd = d;
  hh = h;
  hi = false;
  hk = false;
}

std::string Object::getName() {
  return hn;
}

std::string Object::getDesc() {
  return hd;
}

bool Object::isHidden() {
  return hh;
}

void Object::printObject() {
  std::cout << "Object: " << hn << "\n" << hd << std::endl;
}

bool Object::isKey() {
  return hk;
}

bool Object::isItem() {
  return hi;
}

