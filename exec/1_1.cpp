#include <iostream>
#include <string>

using namespace std;

bool isUnique(string str)
{
  bool *p = new bool[200]();

  for(int i=0; i < str.length(); ++i) {
    //char val = "" 
    if (str.at(i))
    {
      return false;
    } else {
      str.at(i) = true; 
    }
  }

  return true;
}

int main(int argc, char const *argv[])
{
  string str = "abce";
  if(isUnique(str)) {
    cout<< "there's no repitition" << endl;
  } else {
    cout<< "there's repitition" << endl;
  }


    
  return 0;
}
