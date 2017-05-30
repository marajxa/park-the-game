/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the main file for the Key class.
 */

#include "Key.h"
#include "Object.h"
#include "Room.h"
#include <string>

Key::Key(std::string n, std::string d, bool h, int* r): Object(n,d, h) {
  hn = n;
  hd = d;
  hr = r;
  hk = true;
}

int* Key::getRef() {
  return hr;
}
