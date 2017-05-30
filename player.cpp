/*
 * Clare Allsopp-Shiner, Nora Broderick, Samantha Kacir, and Sophie Rehrig
 * CS246 - David Cooper
 * Final Project
 * This is the player class for our game.
 */

#include "player.h"

//constructor
Player::Player(){
  currentRoom = NULL;
  backpack = new Inventory();
  nextTurn = this;
  motivation = 100;
}

Player::Player(Room* r) {
  currentRoom = r;
  backpack = new Inventory();
  nextTurn = this;
  motivation = 100;
}

//deconstructor
Player::~Player(){
}

//test if the game has been won
bool Player::isWin(Room* goal){
  if(currentRoom == goal){
    return true;
  }
  else{
    return false;
  }
}

//allow the player or program to see what is currently in inventory
Inventory* Player::lookInBackpack(){
  std::cout << "Your backpack contains ";
  backpack->printHold();
  //std:cout << std::endl;
  return backpack;
}

//add an item to the inventory
void Player::add(Item* i){
  backpack->add(i);
  std::cout << "There is now " << i->getName() << " in your backpack." << std::endl;
}

//add a key to the inventory
void Player::add(Key* i){
  backpack->add(i);
  std::cout << "There is now " << i->getName() << " in your backpack." << std::endl;
}

//remove an item from the inventory
void Player::remove(Item* i){
  std::cout << "You took " << i->getName() << " out of your backpack." << std::endl;
  backpack = backpack->remove(i);
}

//remove a key from the inventory
void Player::remove(Key* i){
  std::cout << "You took " << i->getName() << " out of your backpack." << std::endl;
  backpack = backpack->remove(i);
}

//use an item
void Player::use(Item* i){
  int m = i->getMotivation();
  if(m<0){
    loseMotivation(-1*m);
  }
  else{
    getMotivation(m);
  }
  remove(i);
}

//use a key
void Player::use(Key* i){
  //i.use();
  useKey(currentRoom,i); //added by Sophie
  remove(i);
}

//return the room the player is currently in
Room* Player::getCurrentRoom(){
  currentRoom->printOptions();
  //currentRoom->inventory->printHold();
  return currentRoom;
}

//gain motivation! (add points)
void Player::getMotivation(int points){
  motivation += points;
}

//subract points from the current motivation
void Player::loseMotivation(int points){
  motivation -= points;
}

//returns the player's motivation
int Player::seeMotivation(){
  return motivation;
}

void Player::getUserInput(){
  getCurrentRoom();
  char a;
  if(currentRoom->enemy != NULL &&
     !(backpack->sizeOfI() == 0 && currentRoom->inventory->sizeOfI() == 0)){
    std::cout << "What would you like to do next?" << std::endl
	      << "m = move to a new room" << std::endl
	      << "i = interact with the inhabitant of a room" << std::endl
	      << "d = do something with an item" << std::endl
	      << "or q to quit" << std::endl;
  }
  else if(currentRoom->enemy != NULL &&
	  (backpack->sizeOfI() == 0 && currentRoom->inventory->sizeOfI() == 0)){
    std::cout << "What would you like to do next?" << std::endl
	      << "m = move to a new room" << std::endl
	      << "i = interact with the inhabitant of a room" << std::endl
	      << "or q to quit" << std::endl;
  }
  else if(currentRoom->enemy == NULL &&
	  !(backpack->sizeOfI() == 0 && currentRoom->inventory->sizeOfI() == 0)){
    std::cout << "What would you like to do next?" << std::endl
	      << "m = move to a new room" << std::endl
	      << "d = do something with an item" << std::endl
	      << "or q to quit" << std::endl;
  }
  else{
    std::cout << "What would you like to do next?" << std::endl
	      << "m = move to a new room" << std::endl
	      << "or q to quit" << std::endl;
  }
  cin >> a;
  if(toupper(a) == 'M'){
    switchRooms(getDirection());
  }
  else if(toupper(a) == 'I'){
    //Sophie fiddled with this code from here...
    //int m;
    int m = currentRoom->enemy->talk(this->backpack);
    //..to here
    if(m < 0){
      loseMotivation(-1*m);
    }
    else{
      getMotivation(m);
    }
  }
  else if(toupper(a) == 'D'){
    getItemInput();
  }
  else if(toupper(a) == 'Q'){    
    /*char b;
    std::cout << "Would you like to save the game?" << std::endl;
    cin >> b;
    if(toupper(b) == 'Y'){
      //saveGame();
      }*/
    loseMotivation(seeMotivation()+1);    
  }
  else{
    std::cerr << "ERROR: Invalid input. Please try again." << std::endl;
    getUserInput();
  }
}

//get user input as to what should be done with an item
void Player::getItemInput(){
  char a;
  //std::cout << "Printing...." ;
  Inventory* i = currentRoom->inventory;
  //std::cout << "Got it!" << std::endl;
  if( backpack-> sizeOfI() != 0  && i->sizeOfI() != 0 ){
    std::cout << "What would you like to do?" << std::endl
	      << "p = pick up an item" << std::endl
	      << "d = drop an item" << std::endl
	      << "u = use an item" << std::endl
	      << "or 'b' to go back.  ";
    }
  else if( backpack-> sizeOfI() != 0 ){
    std::cout << "What would you like to do?" << std::endl
	      << "u = use an item" << std::endl
	      << "d = drop an item" << std::endl
	      << "or 'b' to go back.  ";
  }
  else{
    std::cout << "What would you like to do?" << std::endl
	      << "p = pick up an item" << std::endl
	      << "or 'b' to go back.  ";
	      }
  cin >> a;
  if(toupper(a) == 'P'){
    int i;
    std::cout << "Which item would you like to pick up?" << std::endl;
    currentRoom->inventory->printHold();
    cin >> i;
    if(i>currentRoom->inventory->sizeOfI() || i<1){
      do{
	std::cerr << "ERROR: item not in room." << std::endl;
	currentRoom->inventory->printHold();
	cin >> i;
      }while(i>currentRoom->inventory->sizeOfI() || i<1);
    }
    Object* o = currentRoom->inventory->getFromPos(i);
    if(o->isKey()){
      Key* p = static_cast<Key*>(o);
      currentRoom->inventory->remove(p);
      add(p);
    }
    else if (o->isItem()){
      Item* p = static_cast<Item*>(o);
      currentRoom->inventory->remove(p);
      add(p);
    }
       
  }
  else if(toupper(a) == 'D'){
    int i;
    std::cout << "Which item would you like to drop?" << std::endl;
    backpack->printHold();
    cin >> i;
    if(i>backpack->sizeOfI() || i<1){
      do{
	std::cerr << "ERROR: item not in backpack." << std::endl;
	backpack->printHold();
	cin >> i;
      }while(i>backpack->sizeOfI() || i<1);
    }
    Object* o = backpack->getFromPos(i);
    if(o->isKey()){
      Key* p = static_cast<Key*>(o);
      currentRoom->inventory->add(p);
      remove(p);
    }
    else if (o->isItem()){
      Item* p = static_cast<Item*>(o);
      currentRoom->inventory->add(p);
      remove(p);
    }
  }
  else if(toupper(a) == 'U'){
    int i;
    std::cout << "Which item would you like to use?" << std::endl;
    backpack->printHold();
    cin >> i;
    if(i>backpack->sizeOfI() || i<1){
      do{
	std::cerr << "ERROR: item not in backpack." << std::endl;
	backpack->printHold();
	cin >> i;
      }while(i>backpack->sizeOfI() || i<1);
    }
    Object* o = backpack->getFromPos(i);
    if(o->isKey()){
      Key* p = static_cast<Key*>(o);
      use(p);
    }
    else if (o->isItem()){
      Item* p = static_cast<Item*>(o);
      use(p);
    }
  }
  else if(toupper(a) == 'B'){
    getUserInput();
  }
  else{
    std::cerr << "ERROR: Invalid input. Please try again." << std::endl;
    getItemInput();
  }
}
  
  

//get user input for direction
Room::directions Player::getDirection(){
  char a;
  std::cout << "Which direction would you like to go in? (n, e, s, w, u, d or b to go back) ";
  cin >> a;
  if(a == 'n' || a=='N'){
    return Room::NORTH;
  }
  else if(a == 'e' || a == 'E'){
    return Room::EAST;
  }
  else if(a == 's' || a == 'S'){
    return Room::SOUTH;
  }
  else if(a == 'w' || a == 'W'){
    return Room::WEST;
  }
  else if(a == 'u' || a == 'U'){
    return Room::UP;
  }
  else if(a == 'd' || a == 'D'){
    return Room::DOWN;
  }
  else if(a == 'b' || a == 'B'){
    getUserInput();
  }
  else{
    std::cerr << "ERROR: Invalid direction. Please try again." << std::endl;
    return getDirection();
  }
}

//moves the player to a new room
void Player::switchRooms(Room* r){
  //if r is a neighbor of currentRoom
  if(getCurrentRoom()->neighbor(r)){
    currentRoom = r;
  }
  else{
    std::cerr << "ERROR: " << r->getName() << " IS NOT ADJACENT TO THE ROOM YOU ARE IN" << std::endl;
  }
}

void Player::switchRooms(Room::directions d){
  //if there is a room in that direction
  //and it is unlocked
  currentRoom = currentRoom->move(d);
}

//returns true if motivation > 0
bool Player::alive(){
  if(motivation <= 0){
    return 0;
  }
  else{
    return 1;
  }
}

//kill enemy
void Player::kill(Enemy e){
  e.kill();
}
