
#include <iostream>
#include <string>
#include "DCooper.h"
#include "Key.h"

using namespace std;

DCooper::DCooper(){
  name = "David Cooper";
  des = "Your computer science professor";
  inventory = new Inventory();
}

DCooper::~DCooper(){

}


int DCooper::talk(Inventory* i){
  string into;
  string into2;
  string into3;
  //bool notHide = false;
  //Key Pointer
  //int* r;
  //Key* lab_key = new Key("Lab Key", "It's the key to the lab", notHide, r);
  cout << name << ": " << "Hello, what do you want?" << endl;
  cout << "A: Nothing" << endl;
  cout << "B: Do you have a key?" << endl;
  cout << "C: I have a question about my project " << endl;

  cin >> into;
  if (into == "A" || into == "a"){
    cout << name << ": " << "Well, if you need anything I'm here" << endl;
    cout << " " << endl;
    cout << "MOTIVATION STAYS THE SAME" << endl;
    return 0;
  } else if(into == "B" || into == "b"){
    cout << name << ": " << "A key to what?" << endl;
    cout << "A: Any key really" << endl;
    cout << "B: A key to the lab" << endl;
    cin >> into2;
    if(into2 == "A" || into2 == "a"){
      cout << name << ": " << "Well, I can't just give you any key" << endl;
      cout << " " << endl;
      cout << "LOST 5 MOTIVATION" << endl;
      return 0;
    }else if(into2 == "B" || into2 == "b"){
      cout << name << ": " << "Why do you need a key to the lab?" << endl;
      cout << " " << endl;
      cout << "LOST 2 MOTIVATION" << endl;

      return -2;
      
    }else{
      cout << "invalid input" << endl;
    }
  }else if(into == "C" || into == "c"){
    cout << name << ": " << "I have an answer" << endl;
    cout << "A: If we go to the lab I'll show you my problem" << endl;
    cout << "B: nevermind" << endl;
    cin >> into3;
    if (into3 == "A" || into3 == "a"){
      cout << name << "; " << "Sure, let's go" << endl;

      Key* key = static_cast<Key*>(inventory->getFromPos(1));
      i->add(key);
      //pl->add(lab_key);
      inventory->remove(key);

      cout << " " << endl;
      cout << "GAIN  5 MOTIVATION" << endl;
      return 5;
    }else if (into3 == "B" or into3 == "b"){
      cout << name << ": " << "Well if you need anything..." << endl;
      cout <<" " << endl;
      cout << "MOTIVATION STAYS THE SAME" << endl;
      return 0;
    }else{
      cout << "invalid input" << endl;
      return 0;
    }
  }else{
    cout << "invalid input" << endl;
    return 0;
  }

}
