#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void print(int array[], int num)
{

  for (int i = 0; i < num; ++i)
  {
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int a[] = {13,19,9,5,12,8,7,4,21,2,6,11};

  print(a, 12);
  quick_sort(a, 0, 11);
  print(a, 12);

  return 0;
}
