/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the header file for the Key class.
 *
 *Note: The Key using a linking pointer to work. The same pointer is give to a key and the room which contains the door it unlocks. The value of the pointer is the door that the key unlocks.
 */

#ifndef Key_H
#define Key_H

#include <string>
#include "Object.h"

class Key : public Object{
  int* hr; //the linking pointer; this must be the same pointer as the room gets
 public:
  Key(std::string hn, std::string hd, bool hh, int* hr); //name, description, if it is hidden, and the linking pointer
  int* getRef(); //returns the linking pointer
};


#endif
