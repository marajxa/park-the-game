#include <iostream>
#include <string>
#include "Doug.h"
#include "Key.h"

using namespace std;

Doug::Doug(){
  name = "Doug Blank";
  des = "It's Doug";
  inventory = new Inventory();
}

Doug::~Doug(){

}

int Doug::talk(Inventory* i){
  string into;
  string into2;
  //bool notHide = false;
  //Key Pointer
  //int* r;
  //Key* off_key = new Key("Key to Dianna's Office", "Exactly what it says it is", notHide, r);
  
  cout << "Oh! Hey there" << endl;

  cout << "A: Hey Doug" << endl;
  cout << "B: Do you know where I can get the key to the lab?" << endl;

  cin >> into;

  if(into == "A" or into == "a"){
    cout << name << ": What are you doing here so late?" << endl;
    cout << "A: I'm trying to finish my project, but I'm locked out of the lab" << endl;
    cout << "B: dying" << endl;

    cin >> into2;

    if(into2 == "A" or into2 == "a"){
      cout << name << ": Good luck. Why don't you talk to Dianna, she'll be able to help you. Here, take this." << endl;

      Key* key = static_cast<Key*>(inventory->getFromPos(1));
      i->add(key);
      //i->add(off_key);
      inventory->remove(key);
      
      cout << " " << endl;
      cout << "GAIN 5 MOTIVATION" << endl;
      return 5;
    }else if(into2 == "B" or into2 == "b"){
      cout << name << ": Oh dear, you'll do fine" << endl;
      cout << " " << endl;
      cout << "GAIN 2 MOTIVATION" << endl;
      return 2;
    }else {
      cout << "invalid" << endl;
      return 0;
    }
  }else if(into == "B" or into == "b"){
    cout << name << ": Talk to Dianna, she might be able to help " << endl;
    cout << " " << endl;
    cout << "GAIN 2 MOTIVATION" << endl;
    return 2;
  }else{
    cout << "invalid" << endl;
    return 0;
  }  
}
