#include <iostream>
#include <string>
#include "Haverbro.h"

using namespace std;

Haverbro::Haverbro(){
  name = "Lost Haverbro";
  des = "He is lost and afraid, when was the last time he saw daylight?";
}

Haverbro::~Haverbro(){

}

int Haverbro::talk(){
  string into;
  string into2;
  cout << name << ": *SCREAMING* " << endl;
  cout << "A: just walk away" << endl;
  cout << "B: Are you okay there buddy?" << endl;

  cin >> into;

  if (into == "A"){
    cout << "you think leaving him alone is the best option" << endl;
    cout << "LOST 5 MOTIVATION" << endl;
    return -5;
  }else if (into == "B"){
    cout << name << ": sorry, I can't find the exit. I don't know where I am or how long I've been here." << endl;

    cout<< "A: That's alright, you just startled me. Keep going straight and and I'm sure you'll find your way out" << endl;
    cout << "B: I have no idea where I am either" << endl;
    
    cin >> into2;

    if (into2 == "A"){
      cout << name << ": Thank you " << endl;
      cout << "GAINED 1 MOTIVATION" << endl;
      return 1;
    }else if(into2 == "B"){
      cout << name << ": I'm going to die in here bro " << endl;
      cout << "LOST 5 MOTIVATION" << endl;
      return -5;
    }else{
      cout << "invalid" << endl;
      return 0;
    }
    
  } else {
    cout << "invalid" << endl;
    return 0;
  }
}
