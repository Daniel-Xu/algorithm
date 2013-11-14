#include <stdlib.h>
#include "binary_tree.h"

//create node
static link make_node(int val) 
{
  link p = malloc(sizeof(node));
  p->val = val;

  return p;
}

static void free_node(link p)
{
  free(p);
}

link init_tree(int inorder[], int preorder[], int num)
{
  link t = NULL;
  int k;

  if(num <= 0)
    return NULL;

  //separate left and right
  for(k=0; preorder[0] != inorder[k]; ++k);
  t = make_node(preorder[0]);

  t->left = init_tree(inorder, preorder+1, k);
  t->right = init_tree(inorder+k+1, preorder+k+1, num-k-1);

  return t;
}

void post_order(link t, void (*visit)(link))
{
  if(!t)
    return;
  post_order(t->left, visit);
  post_order(t->right, visit);

  visit(t);
}
void pre_order(link t, void (*visit)(link))
{
  if(!t)
    return;
  visit(t);
  pre_order(t->left, visit);
  pre_order(t->right, visit);
}
void in_order(link t, void (*visit)(link))
{
  if(!t)
    return;

  in_order(t->left, visit);
  visit(t);
  in_order(t->right, visit);
}

int depth(link t)
{
  int dl, dr;
  if(!t)
    return 0;

  dl = depth(t->left);
  dr = depth(t->right);

  return 1 + ((dl>dr)?dl:dr);
}

int node_num(link t)
{
  if(!t)
    return 0;

  return 1 + node_num(t->left)+node_num(t->right);
}

void destroy(link t)
{
  post_order(t, free_node);
}
