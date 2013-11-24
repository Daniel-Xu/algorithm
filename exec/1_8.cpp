#include <iostream>

using namespace std;

bool isSubsString(string s1, string s2)
{
  if(s1.find(s2) != string::npos)
    return true;
  else 
    return false;
}

bool isRotation(string s1, string s2)
{
  if(isSubsString(s1, s2)) 
    return true;
  else
    return false;
}


int main(int argc, char const *argv[])
{
  string s1 = "erbottlewat";
  string s2 = "waterbottle";

  string s3 = s1 + s1;

  if(isRotation(s3, s2))
    cout << "yes" << endl;
  else 
    cout << "no" << endl;

  return 0;
}
