#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

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
  /*int a[] = {8, 9, 18, 2, 3};*/
  int a[] = {5,13,2,25,7,17,20,8,4};
  
  print(a, 9);
  heap_sort(a, 9);
  print(a, 9);

  return 0;
}
