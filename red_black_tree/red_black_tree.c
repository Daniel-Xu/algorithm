#include "red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

static link make_node(int val)
{
  link p = malloc(sizeof(node));
  p->val = val;
  p->left = p->right = NULL;

  return p;
}

tree *new_tree(void)
{
    tree *rb_tree = malloc(sizeof(tree));
    rb_tree->root = NULL;
    return rb_tree;
}



//two situation need to be considered
//remember that the root's parent will be set null in insert
//first: x is the root 
//second: the child is nil, because nil.parent will cause segf
void left_rotation(tree *rb, link x) {
    //we aim at left rotation, so x.right must exist
    link y  = x.right;

    //handle y's parent and y 
    y.parent = x.parent;
    if (x.parent == NULL)
        rb->root = y;
    else if(x.parent.left == x)
        x.parent.left = y;
    else 
        x.parent.right = y;

    //handle y.left and x
    x.right = y.left;
    if(y.left != NULL)
        y.left.parent = x;

    //handle x.parent and y
    x.parent = y;
    y.left = x;
}

void right_rotation(tree *rb, link x) { 
    link y = x.left;

    //handle y and x.parent
    y.parent = x.parent;
    if(x.parent == NULL)
        rb->root = y;
    else if(x.parent.left == x)
        x.parent.left = y;
    else
        x.parent.right = y;

        
    //handle the x.left with y.right
    x.left = y.right;
    if(y.right != NULL)
        y.right.parent = x;

    //handle the x.parent with y
    x.parent = y;
    y.right = x;
}





//pre order
void pretty_print(link p, int indent)
{
    if(p != NULL) {
        if(indent) {
            for (int i = 0; i < indent; ++i)
            {
                printf(" ");
            }
        }
        printf("%d\n", p->val);
        printf("\n");
        if(p->left) {
            pretty_print(p->left, indent-1);
        }
        
        if(p->right) {
            pretty_print(p->right, indent+1);
        }
    }
}
