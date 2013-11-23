#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

string compress(string src)
{
  string::iterator p = src.begin();
  string::iterator q = p+1;

  int count = 1;
  string ret;

  while(q != src.end()) {
    if(*p == *q) {
      q++; 
      count++;
    } else {
      ret += *p; 
      ret += to_string(count);
      p = q;
      q = q+1;
      count = 1;
    }
  }
  ret += *p;
  ret += to_string(count);

  if(ret.length() >= src.length())
    return src;
  else
    return ret;
}

int main(int argc, char const *argv[])
{
  
  string src;
  cout << "please input source string" << endl;
  cin >> src;
  
  cout << "compressed string is: " << compress(src) << endl;

  return 0;
}
