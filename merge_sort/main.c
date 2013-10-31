#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void print(int array[], int num)
{

  for (int i = 0; i < num; ++i)
  {
    printf("%d\n", array[i]);
  }
}

int main(int argc, char const *argv[])
{
  int a[] = {4, 4,1, 3, 5};
  merge_insertion(a, 0, 4);
  print(a, 5);


  return 0;
}
