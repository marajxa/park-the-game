#include <iostream>
#include <string>
#include "HMajor.h"

using namespace std;

HMajor::HMajor(){
  name = "Humanities Majot";
  des = "What are they doing in Park?";
}

HMajor::~HMajor(){

}

int HMajor::talk(){
  string into;
  string into2;

  cout << name << ": Oh hi! Are you a STEM major? " << endl;
  cout << "A: Yeah " << endl;
  cout << "B: Why are you asking?" << endl;

  cin >> into;
  if(into == "A"){
    cout << name <<": Do you think you could help me with my math homework?" << endl;
    cout << "A: I'm not a TA" << endl;
    cout << "B: I'm a Comp Sci major" << endl;

    cin >> into2;

    if(into2 == "A"){
      cout << name << ": You didn't have to be so rude about it" << endl;
      cout << " " << endl;
      cout << "LOST 3 MOTIVATION, BUT OH THE SWEET SATISFACTION" << endl;
      return -3;

    }else if(into == "B"){
      cout << name << ": oh, well... " << endl;
      cout << " " << endl;
      cout << "LOST 2 MOTIVATION" << endl;
      return -2;
    }else{
      cout << "invalid" << endl;
      return 0;
    }
    
  }else if(into == "B"){
    cout << name << ": ..nevermind" <<endl;
    cout << " " << endl;
    cout << "LOST 2 MOTIVATION" << endl;
    return -2;
  }else{
    cout<<"invalid"<<endl;
    return 0;
  }
}
