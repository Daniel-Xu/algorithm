#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

int main(int argc, char const *argv[])
{
  int x;
  link a = create_single_list();
  print_link(a);

  printf("delete\n");
  
  /*printf("please input what node you want to delete\n");*/
  /*scanf("%d", &x);*/
  /*print_link(delete_node(a, x));*/

  printf("begin to reverse...\n");
  print_link(reverse_link(a));

  return 0;
}
