/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is a header file for the Object class.
 */

#ifndef Object_H
#define Object_H

#include <string>

class Object {
 protected:
  std::string hn; //name that the player sees
  std::string hd; //description
  bool hh; //is this object hidden
  bool hi; //is this an item
  bool hk; //is this a key
 public:
  Object(std::string hn, std::string hd, bool hh);
  std::string getName(); //returns hn
  std::string getDesc(); //returns hd
  void printObject(); //prints out the name and description in a user-friendly format
  bool isHidden(); //returns hh
  bool isKey();
  bool isItem();
};

#endif
