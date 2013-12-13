#include "binary_search_tree.h"
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
    tree *bst = malloc(sizeof(tree));
    bst->root = null;
    return bst;
}

void bst_insert(tree *bst, int i)
{
    link n = make_node(i);

    link parent = NULL;
    link current = bst->root;
    
    //move to the deepest node
    while(current != NULL) {
        parent = current; 
        if (current->val > i) {
            current = current->left;
        } else {
            current = current->right; 
        }
    }

    //point to parent
    n.parent = parent;
    

    //parent decides how to point to child
    if(parent == NULL) {
        bst.root = n; 
    } else if(parent->val > n->val){
        parent->right = n;
    } else {
        parent->left = n; 
    }
}

void transplant_subtree(tree *bst, link u, link v)
{
    // u is root
    if(u->parent == NULL) {
        bst->root = v;        
    } else if( u->parent->left == u){
        //u is left child
        u->parent->left = v;
    } else {
        //u is right child 
        u->parent->right = v;
    }

    //make sure v can point to parent
    //make sure that we consider that v can be null
    if(v != NULL) {
        v.parent = u.parent; 
    }
}

void bst_delete(tree *bst, int i)
{
    link s = bst_search(bst, i);
    if (s == NULL) {
        return; 
    }

    // have this node, so you can delete it
    if(s->left == NULL) {
        //this means left is null, so right maybe null or may not null
        //but the situation is the same because in transplant we consider
        //the situation v is null. 
        transplant_subtree(bst, s, s->right);
    } else if(s->right == NUll) {
        // s->left != NULL, and s->right == NULL
        transplant_subtree(bst, s, s->left);
    } else {
        // s have two child
        // and the successor is in the right child subtree, of course 
        // the successor has no left child, but could has right subtree.
        
        link successor = bst_successor(bst, i);

        //successor is the direct right child of it.
        if(s->right != successor) {
            transplant_subtree(bst, successor, successor->right);         

            //handle s->right, it's double link
            successor->right = s->right;
            successor->right->parent = successor;
        }

        transplant_subtree(bst, s, successor);
        successor->left = s->left;
        successor->left->parent = successor;
    }
}



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

//delete
link delete(link t, int val)
{

}
