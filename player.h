/*
 * Clare Allsopp-Shiner, Nora Broderick, Samantha Kacir, and Sophie Rehrig
 * CS246 - David Cooper
 * Final Project
 * This is the header file for the player class for our game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include "Room.h"
#include "Enemy.h"
#include "functions.h"

//class Room;
//class Enemy;
class Player{
  Room* currentRoom;
  Inventory* backpack;
  //for now, current player. 
  Player* nextTurn;
  int motivation;
 public:
  //constructor
  Player();
  Player(Room* r);
  //deconstructor
  ~Player();
  //test if the game has been won
  bool isWin(Room* goal);
  //allow the player or program to see what is currently in inventory
  Inventory* lookInBackpack();
  //add an item to the inventory
  void add(Item* i);
  void add(Key* i);
  //remove an item from the inventory
  void remove(Item* i);
  void remove(Key* i);
  //use an item in the inventory
  void use(Item* i);
  void use(Key* i);
  //return the room the player is currently in
  Room* getCurrentRoom();
  //gain motivation! (add points)
  void getMotivation(int points);
  //subract points from the current motivation
  void loseMotivation(int points);
  //returns the player's motivation
  int seeMotivation();
  //moves the player to a new room
  void switchRooms(Room* r);
  void switchRooms(Room::directions d);
  //get user input for direction
  Room::directions getDirection();
  //get user input
  void getUserInput();
  //get user input as to what should be done with an item
  void getItemInput();
  //returns true if motivation > 0
  bool alive();
  //kill enemy
  void kill(Enemy e);
};
#endif
