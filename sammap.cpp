/*
 * Clare Allsopp-Shiner, Nora Broderick, Samantha Kacir, and Sophie Rehrig
 * CS246 - David Cooper
 * Final Project
 * This builds the map of park
 */

#include <iostream>
#include <string>
#include "functions.h"
#include "Room.h"
#include "totalEnemy.h"
#include "Item.h"

void buildPark(Room** ret) {

  //add enemies
  DCooper* dc = new DCooper();
  Doug* db = new Doug();
  DXu* dx = new DXu();
  Frosh* lostFrosh = new Frosh();
  Haverbro* haverbro = new Haverbro();
  HMajor* humanitiesMajor = new HMajor();
  //make keys and link to rooms
  int lab_key_d = 2;
  int* lab_key_ref = &lab_key_d;
  Key* lab_key = new Key("Lab Key","It's the key to the lab",false,lab_key_ref);
  int dxu_key_d = 4;
  int* dxu_key_ref = &dxu_key_d;
  Key* dxu_key = new Key("Key to Dianna's Office", "Exactly what it says it is", false, dxu_key_ref);
  int dcooper_key_d = 4;
  int* dcooper_key_ref = &dcooper_key_d;
  Key* dcooper_key = new Key("Office Key", "it leads to Cooper's Office", false, dcooper_key_ref);
  //add to their inventories
  dc->inventory->add(lab_key);
  db->inventory->add(dxu_key);
  dx->inventory->add(dcooper_key);
  
  Room* entry = new Room("Entryway");
  Item* umbrella = new Item("Umbrella", "If it's raining when you leave, at least you won't get wet.", false, 2);
  entry->inventory->add(umbrella); 
  Room* postbacLounge = new Room("Postbac Lounge",entry,NULL,NULL,NULL,NULL,NULL);
  Item* smell = new Item("Bad Smell", "Ew.", false, -5);
  postbacLounge->inventory->add(smell); 
  Room* csOffices = new Room("CS Offices Hallway",NULL,NULL,entry,NULL,NULL,NULL);
  csOffices->setRef(dxu_key_ref);
  Room* dxuOffice = new Room("Professor Xu's Office",NULL,csOffices,NULL,NULL,NULL,NULL);
  dxuOffice->enemy = dx;
  dxuOffice->eLock();
  Room* dblankOffice = new Room("Professor Blank's Office",NULL,NULL,csOffices,NULL,NULL,NULL);
  dblankOffice->enemy = db;;
  Item* robot = new Item("Robot", "A tiny robot", false, 5);
  dblankOffice->inventory->add(robot); 
  Room* hallway0 = new Room("Hallway", NULL, NULL,NULL,entry,NULL,NULL);
  Room* hallway1 = new Room("Hallway", NULL, NULL,hallway0,NULL,NULL,NULL);
  Room* hallway4 = new Room("Hallway", NULL,NULL,NULL,hallway0, NULL ,NULL);
  hallway4->enemy = lostFrosh;
  Room* bathroom = new Room("Bathroom" , NULL,hallway1,NULL,NULL,NULL,NULL);
  Room* hallway2 = new Room("Hallway" ,NULL,NULL,hallway1,NULL,NULL,NULL);
  Room* hallway3 = new Room("Hallway" ,NULL,NULL,hallway2, NULL, NULL,NULL);
  hallway2->setRef(dcooper_key_ref);
  Room* lab = new Room("Lab" ,NULL,NULL,NULL,hallway3,NULL,NULL);
  lab->wLock();
  hallway3->setRef(lab_key_ref);
  Room* dcooperOffice = new Room ("Professor Cooper's Office",NULL,hallway2,NULL,NULL,NULL,NULL);
  dcooperOffice->enemy = dc;
  dcooperOffice->eLock();
  Room* hallway5 =  new Room("Hallway", NULL,NULL,hallway3,NULL,NULL,NULL);
  Room* hallway6 = new Room("Hallway", NULL,NULL,NULL,NULL,NULL,hallway5);
  Room* hallway7 = new Room("Hallway", hallway6, NULL, NULL, NULL,NULL,NULL );
  Room* library1 = new Room("Library",NULL,hallway6,NULL,NULL,NULL,NULL);
  library1->enemy = haverbro;
  Item* txtbook = new Item("A CS textbook!", "It'll probably help!", false, 5);
  library1->inventory->add(txtbook); 
  Room* library2 = new Room("Library",library1,hallway7,NULL,NULL,NULL,NULL);
  Item* book = new Item("A book", "It's not even that interesting", false, 0);
  library2->inventory->add(book); 
  Room* hallway8 = new Room("Hallway",hallway7,NULL,NULL,NULL,NULL,NULL);
  Room* hallway9 = new Room("Hallway",hallway8,NULL,NULL,NULL,NULL,NULL);
  Room* mathOffice = new Room("Math Office",NULL,NULL,NULL,hallway8,NULL,NULL);
  Room* hallway10 = new Room("Hallway",hallway9,NULL,NULL,NULL,NULL,NULL);
  Room* hallway11 = new Room("Hallway",NULL,NULL,NULL,hallway10,NULL,hallway4);
  Room* hallway12 = new Room("hallway",NULL,NULL,NULL,hallway11,NULL,NULL);
  Room* hallway13 = new Room("hallway",NULL,NULL,NULL,hallway12,NULL,NULL);
  Room* hallway14 = new Room("hallway",NULL,NULL,NULL,hallway13,NULL,NULL);
  Room* room336 = new Room("Room 336",NULL,NULL,hallway12,NULL,NULL,NULL);
  Room* room337 = new Room("Room 337",NULL,NULL,hallway13,NULL,NULL ,NULL);
  Room* room338 = new Room("Room 338",NULL,NULL,hallway14,NULL,NULL,NULL);
  room338->enemy = humanitiesMajor;
  Room* hallway15 = new Room("Hallway",NULL,NULL,NULL,NULL,NULL,room337);
  Room* mathGradLounge = new Room("Math Grad Lounge",NULL,NULL,hallway15,NULL,NULL,NULL);
  Item* coffee = new Item("A cup of coffee", "Piping hot, but full of caffeine", false, 15);
  mathGradLounge->inventory->add(coffee); 
  Room* physicsLounge = new Room("Physics Lounge",NULL,NULL,NULL,hallway15,NULL,NULL);

  //goal->printOptions();
  
  //std::cout << ret << std::endl;

  Room* rettby[] = {entry, lab, postbacLounge, csOffices, dxuOffice, dblankOffice,
	 hallway0, hallway1, hallway4, bathroom, hallway2, hallway3,
	 dcooperOffice, hallway5, hallway6, hallway7, library1, library2,
	 hallway8, hallway9, mathOffice, hallway10, hallway11, hallway12,
	 hallway13, hallway14, room336, room337, room338, hallway15,
	 mathGradLounge, physicsLounge};
  
  /*
  ret[0] = entry;
  ret[1] = lab;
  */

  for(int i=0; i< 32; ++i){
    ret[i] = rettby[i];
  }

  //ret[0]->printOptions();
  
  //return ret;
}
