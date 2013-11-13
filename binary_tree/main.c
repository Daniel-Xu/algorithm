#include <stdio.h>
#include "binary_tree.h"


#define NODE_N 6

void visit(link t)
{
  printf("%d\t", t->val);
}

int main(int argc, char const *argv[])
{
  int in[] = {1, 2, 3, 4, 5, 6};
  int pre[] = {4, 2, 1, 3, 5, 6}; 

  link t = init_tree(in, pre, NODE_N);
  
  post_order(t, visit);
  printf("\n");
  pre_order(t, visit);
  printf("\n");
  in_order(t, visit);
  printf("\n");
  
  printf("================node number==============\n");
  printf("%d\n", node_num(t));

  printf("\n");

  destroy(t);
  
  return 0;
}
