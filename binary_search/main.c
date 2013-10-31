#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

void print(int array[], int num)
{

  for (int i = 0; i < num; ++i)
  {
    printf("%d\n", array[i]);
  }
}

int main(int argc, char const *argv[])
{
  int a[] = {1, 2, 3, 3, 5, 7, 8};
  int num;
  scanf("%d", &num);

  int res = binary_search(a, 0, 6, num);

  print(a, 7);
  printf("specific num is: %d\n", num);

  if (res != -1) 
    printf("there's num in the array, index is %d\n", res);
  else
    printf("none\n");
  return 0;
}
