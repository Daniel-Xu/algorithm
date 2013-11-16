#include "binary_search_tree.h"
#include <stdlib.h>

static link make_node(int val)
{
  link p = malloc(sizeof(node));
  p->val = val;
  p->left = p->right = NULL;
  /*p->parent = NULL;*/

  return p;
}

/*link search(link t, int val)*/
/*{*/
   
/*}*/

//recursive version
link insert(link t, int val)
{
  if(!t)
    return make_node(val);

  if(val > t->val) {
    t->right = insert(t->right, val);
    /*t->right->parent = t;*/
  } else {
    t->left = insert(t->left, val);
    /*t->left->parent = t;*/
  }
  
  return t;
}

/* parent 
//minimum
link tree_mininum(link t)
{

}

//maximum
link tree_maximum(link t)
{

}

//like sorted array, which one is the next one.
link node_successor(link t)
{

}

//transplant is used to change the subtree's parent
void transplant(link t, link src, link subt)
{


}

//delete
link delete(link t, int val)
{

}
*/
