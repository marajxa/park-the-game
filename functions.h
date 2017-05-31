/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *
 *Purpose: This program is a game set in Park Science Building. This file is an h file for non-class functions.
 */

#include "Room.h"
#include "Item.h"

Room* buildNewPark();//builds representation of complete Park, as is right now
Room* buildPark();//builds the representation by creating and connecting rooms and adding their starting inventories, and then returns the starting room
void saveGame(); //prompts user for savefile name and puts all needed info into such a file
void loadGame(std::string savefile); //takes the filename and loads the info from it (could be void, could return current room)
void useKey(Room* room, Key* key); //the room this takes should be the one you are currently in. this will unlock the door associated with the key if the check pointer for the key and room are the same. (srehrig)


