#include <iostream>
#include <cstring>

using namespace std;

// if it's ascii
bool ipUnique1(string str)
{
  bool a[256];
  memset(a, 0, sizeof(a));
  int len = str.length();

  for(int i=0; i < len; ++i) {
    //char val = "" 
    int p = (int)str[i];
    if(a[p]) return false;
    a[p] = true;
  }
  return true;
}

//better for space
bool ipUnique2(string str)
{
  int a[8];
  memset(a, 0, sizeof(a));
  int len = str.length();

  for (int i = 0; i < len; ++i)
  {
    int p = (int)str[i];
    //index position
    int ip = p/32;
    //bit position
    int bp = p%32;

    if(a[ip] & (1 << bp)) return false;
    a[ip] |= 1 << bp;
  }
  return true;
}


//if only a-z
 
bool ipUnique3(string str)
{
  int b = 0;
  int len = str.length();

  for (int i = 0; i < len; ++i)
  {
    int p = (int)str[i];
    int bp = p % 32;

    if(b & (1 << bp)) return false;
    b |= 1 << bp;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  string str;
  while(1){
    cin >> str;
    if(ipUnique3(str)) {
      cout<< "no repitition" << endl;
    } else {
      cout<< "have repitition" << endl;
    }
  }
    
  return 0;
}
