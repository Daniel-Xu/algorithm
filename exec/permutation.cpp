#include <iostream>
#include <cstring>

using namespace std;

void swap(char &a, char &b)
{
  char tmp = a;
  a = b;
  b = tmp;
}
//when you can not figure out what's goning on
//tell yourself calm down 
void permutation(string str, int start, int len)
{
  static int n = 1;
  if( start == (len-1)) {
        
    cout << n++ << endl;
    cout << str << endl;
    
  }
  // permutation's funtion is to traverse 
  for (int i = start; i < len ; ++i)
  {
    swap(str[start], str[i]);
    //cout << str << endl;
    permutation(str, start+1, len);
    //backtrace
    swap(str[start], str[i]);
  }
}

int main(int argc, char const *argv[])
{
  string str;
  cin >> str;
  int len = str.length();
  permutation(str, 0, len);
  return 0;
}
