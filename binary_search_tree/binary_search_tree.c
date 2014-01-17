#include "binary_search_tree.h"
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
    tree *bst = malloc(sizeof(tree));
    bst->root = NULL;
    return bst;
}

void bst_insert(tree *bst, int i)
{
    link n = make_node(i);

    link c_parent = NULL;
    link current = bst->root;
    
    //move to the deepest node
    while(current != NULL) {
        c_parent = current; 
        if (current->val > i) {
            current = current->left;
        } else {
            current = current->right; 
        }
    }

    //point to parent
    n->parent = c_parent;
    

    //parent decides how to point to child
    if(c_parent == NULL) {
        bst->root = n; 
    } else if(c_parent->val > n->val){
        c_parent->left = n;
    } else {
        c_parent->right = n; 
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
        v->parent = u->parent; 
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
    } else if(s->right == NULL) {
        // s->left != NULL, and s->right == NULL
        transplant_subtree(bst, s, s->left);
    } else {
        // s have two child
        // and the successor is in the right child subtree, of course 
        // the successor has no left child, but could has right subtree.
        
        link successor = bst_minimum(s->right);

        //successor is  not the direct right child of it.
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

    free(s);
}

//node successor
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

//minimum
link bst_minimum(link x)
{
    while(x->left != NULL) {
        x = x->left;
    }
    return x;
}

//maximum
link bst_maximum(link x)
{
    while(x->right != NULL)
        x = x->right;

    return x;
}

//search
link bst_search(tree *bst, int i)
{
    link current = bst->root;
    while(current != NULL && i != current->val ){
        if(current->val > i) {
            current = current->left; 
        } else {
            current = current->right; 
        }
    }

    return current;
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
