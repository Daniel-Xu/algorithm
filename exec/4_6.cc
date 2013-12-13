#include <iostream>
//when using inorder to traverse bst, 
//it's a increasing order.
//so the successor is the minumx in all of the bigger node.

link bst_successor(link x)
{
    if(x->right != NULL) {
        return bst_minimum(x->right);
    }

    //no right child, just find the parent
    link y = x->parent;
    while (y != NULL && x == y->right) {
        x = y; 
        y = y->parent;
    }

    return y;
}
