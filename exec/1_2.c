#include <stdio.h>

int main(int argc, char const *argv[])
{
  char str[] = "helloworld";
  char *p = str;
  char *q = &str[sizeof(str)-2];

  while(p < q) {
    char tmp = *p;
    *p = *q;
    *q = tmp;

    p++;
    q--;
  }

    
  printf("%s\n", str);
  return 0;
}
