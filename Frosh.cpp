#include <iostream>
#include <string>
#include "Frosh.h"

using namespace std;

Frosh::Frosh(){
  name = "Timid Freshman";
  des = "This freshman is overwhelmed by life's possiblities";
}

Frosh::~Frosh(){

}

int Frosh::talk(){
  string into;
  string into2;

  cout << name << ": Uh h-hello... " << endl;
  cout << "A: encourage" << endl;
  cout << "B: ignore" << endl;

  cin >> into;
  if(into == "A"){
    cout << "Uh, you can do it.. dude" << endl;
    cout << name << ": REALLY?!" << endl;
    cout << "A: Yeah dude, yeah" << endl;
    cout << "B: Nah man, nah" << endl;

    cin >> into2;

    if(into2 == "A"){
      cout << name << ": Wow thanks! You can do it too!" << endl;
      cout << " " << endl;
      cout << " GAIN 4 MOTIVATION" << endl;
      return 4;
    }else if (into2 == "B"){
      cout << name << ": Why are you lying to me like that?" << endl;
      cout << " " << endl;
      cout << "LOST 2 MOTIVATION" << endl;
      return -2;
    }else{
      cout << "invalid" << endl;
      return 0;
    }

  } else if(into == "B"){

    cout << "okay..." << endl;
    cout << " "<< endl;
    cout << "LOST 5 MOTIVATION " << endl;
    return -5;
  }else{
    cout << "invalid" << endl;
    return 0;
  }
}
