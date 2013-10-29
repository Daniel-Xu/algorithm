#include <stdio.h>
#include "c_insertion_sort.h"

void print(int array[], int num)
{

  for (int i = 0; i < num; ++i)
  {
    printf("%d\n", array[i]);
  }
}

int main(int argc, char const *argv[])
{
  
  int array[] = {5,2, 4, 6};

  insertion_sort(array, 4);
  print(array, 4);

  return 0;
}
