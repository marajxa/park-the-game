#include "player.h"

#include "totalEnemy.h"

//#include "save.h"

#include <iostream>



int main() {
  
  //new game
  Room* lab = new Room("Lab");
  Room** begend = new Room* [32];
  buildPark(begend);
  
  //initialize player in entrance
  Player s = Player(begend[0]);

  Player* p = new Player();
  *p = s;

  //goal room
  lab = begend[1];

  
  do{
    //save(p, begend);
    //lose one point of motivation per turn
    s.loseMotivation(1);
    std::cout << "Your current motivation is: " << s.seeMotivation() << std::endl;
    s.getUserInput();
  }while(s.alive() && ! s.isWin(lab));
  
  if(s.isWin(lab)){
    std::cout <<
      "Congratulations! You submitted your final on time!" << std::endl;
  }
  else{ 
    std::cout <<
      "You lost all motivation and collapsed in a puddle of tears and exhaustion on the floor."
	      << std::endl;
  } 
  
  return 0;
}
