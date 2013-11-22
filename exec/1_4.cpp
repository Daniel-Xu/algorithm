#include <iostream> 
#include <cstring>

using namespace std;

void replace(char *c)
{
  if( c == NULL)
    return;
  int len = strlen(c);
  if(len == 0) 
    return;

  int slen = 0;
  for(int i=0; i<len; i++){
    if(c[i] == ' ') {
      ++slen; 
    }
  }

  slen  = slen*2 + len;

  c[slen--] = '\0';

  for(int i = len-1; i >= 0; --i){
    if(c[i] == ' ') {
      c[slen] = '0';
      c[slen-1] = '2';
      c[slen-2] = '%';
      slen -= 3;
    } else {
      c[slen--] = c[i];
    }
  }
}

int main(int argc, char const *argv[])
{

  char str[1999] = "www.hao 123 . com ";

  replace(str);
  cout << str<< endl;
  return 0;
}
