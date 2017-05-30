#include <iostream>
#include <string>
#include "DXu.h"
#include "Key.h"

using namespace std;

DXu::DXu(){
  name = "Dianna Xu";
  des = "Department Chair";
  inventory = new Inventory();
}

DXu::~DXu(){

}

int DXu::talk(Inventory* i){
  string into;
  string into2;
  string into3;
  //bool notHide = false;
  //Key Pointer. Please change to be more accurate
  //int* r;
  //Key* coop_key = new Key("Office Key", "it leads to Cooper's Office", notHide, r);

  cout << name <<": Hello, do you want to talk about Graphics?" << endl;
  cout << "A: Let's not talk about Graphics" << endl;
  cout << "B: sure..." << endl;
  cout << "C: Actually, I wanted to ask you about something else" << endl;

  cin >> into;

  if(into == "A" or into == "a"){
    cout << name << ": I think you're making a mistake" << endl;
    cout << " " << endl;
    cout << "LOST 2 MOTIVATION" << endl;
    return -2;
  }else if(into == "B" or into == "b"){
    cout << name << ": You are going to suffer, but you will learn a lot"<< endl;
    cout << "A: Not really for me" << endl;
    cout << "B: Do you think I can do it?" << endl;

    cin >> into2;

    if(into2 == "A" or into2 == "a"){

      cout << name << ": please think more about it, I think you have potential" << endl;
      cout << " " << endl;
      cout << "GAIN 2 MOTIVATION " << endl;
      return 1;
      
    }else if(into2 == "B" or into2 == "b"){
      cout << name << ": if you put your mind to it" << endl;
      cout << "A: I think I will take it! Can I get a permission number?" << endl;
      cout << "B: I'll think about it a bit more" << endl;

      cin >> into3;

      if(into3 == "A" or into3 == "a"){

	cout << name << ": Here you go" << endl;

	//i->add(coop_key);
	Key* key = static_cast<Key*>(inventory->getFromPos(1));
	i->add(key);
	inventory->remove(key);
	
	cout << " " << endl;
	cout << "GAIN 5 MOTIVATION " << endl;
	return 5;

      }else if(into3 == "B"){
	cout << name << ": Please do" << endl;
	cout << " " << endl;
	cout << "GAIN 3 MOTIVATION" << endl;
	return 3;
      }else{
	cout << "invalid" << endl;
      }
      
    }else{
      cout << "invalid" << endl;
      return 0;
    }
    
  }else if(into == "C"){

    cout << "what is it?" << endl;
    cout << "A: I need a key?" << endl;
    cout << "B: Do you know where Cooper is?" << endl;

    cin >> into3;

    if (into3 == "A"){
      cout << name << ": what key" << endl;
      cout << " " << endl;
      cout << "LOST 1 MOTIVATION"<<endl;
      return -1;
    }else if(into3 == "B"){

      cout << name << ": He is probably in his office" << endl;
      cout << " " << endl;
      cout << "GAIN 1 MOTIVATION" << endl;
      return 1;

    }else{
      cout << "invalid" << endl;
      return 0;
    }
    
    
  }else{
    cout << "invalid" << endl;
    return 0;
  }
}
