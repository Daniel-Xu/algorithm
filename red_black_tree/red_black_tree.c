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
static void left_rotation(tree *rb, link x) {
    //we aim at left rotation, so x.right must exist
    link y  = x->right;

    //handle y's parent and y 
    y->parent = x->parent;
    if (x->parent == NULL)
        rb->root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else 
        x->parent->right = y;

    //handle y.left and x
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;

    //handle x.parent and y
    x->parent = y;
    y->left = x;
}

static void right_rotation(tree *rb, link x) { 
    link y = x->left;

    //handle y and x.parent
    y->parent = x->parent;
    if(x->parent == NULL)
        rb->root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;

        
    //handle the x.left with y.right
    x->left = y->right;
    if(y->right != NULL)
        y->right->parent = x;

    //handle the x.parent with y
    x->parent = y;
    y->right = x;
}

//search node in red_black_tree
link rb_search_node(tree *rb, int n) {
    link cur = rb->root;

    while(cur != NULL && cur->val != n) {
        if(cur->val > n) 
            cur = cur->left;
        else
            cur = cur->right;
    }

    return cur;
}


//you should know the basic insertion will be like binary search tree
//but it may violate the properties of reb black tree, so after insertion, 
//you need to fix up the properties
void rb_insertion(tree *rb, int n) 
{
    // insertion
    link node = make_node(n);

    link c_parent = NULL;
    link current = rb->root;

    while(current != NULL) {
        c_parent = current;
        if(current->val > n)
            current = current->left;
        else
            current = current->right;
    }

    if(c_parent == NULL) {
        rb->root = node;
    } else if(c_parent->val > n ) {
        c_parent->left = node;
    } else {
        c_parent->right = node;
    }

    node->parent = c_parent;
    node->color = RED;    
     
    //fix up process
    rb_insertion_fix(rb, node);
}

//1.
//six situations
//z.p is red, so z.p is not root, z.p.p exists
//in all case, z.p.p is black
//since violation only between z.p and z

//2. the reason to distinguish uncle's color is to perservet the black height 
void rb_insertion_fix(tree *rb, link x) 
{
     
    //curent node's parent
    link cparent;
    while((cparent=x->parent) && cparent->color == RED) {
        //left side, if it can come in here, we can ensure that x.p.p exists, because 
        //otherwise it will violate the loop invariant: properties of rbt
        
        link gparent = x->parent->parent;
        //the comparison with gparent and cparent is that we can ensure that gparent is black node, kinda like we find the root
        if(cparent == gparent->left) {
            link uncle = gparent->right;
            
            //when uncle is null, it's the same with black node
            if(uncle && uncle->color  == RED){
                //recolor and move the bubble up 
                //recolor aims at perserving the black height
                cparent->color = uncle->color = BLACK;
                gparent->color = RED;
                x = gparent; 
            } else {
                if(x == cparent->right){
                    //case 2, right branch, change it to case3, left branch
                    x = cparent;
                    left_rotation(rb, cparent);
                } else {
                    //case3 , left branch
                    cparent->color = BLACK;
                    gparent->color = RED;
                    right_rotation(rb, gparent);
                }  
            }
        } else {
            //the symetric
            link uncle = gparent->left;
            if(uncle && uncle->color  == RED){
                //recolor and move the bubble up 
                //recolor aims at perserving the black height
                cparent->color = uncle->color = BLACK;
                gparent->color = RED;
                x = gparent; 
            } else {
                if(x == cparent->left){
                    //case 2, right branch, change it to case3, left branch
                    x = cparent;
                    right_rotation(rb, cparent);
                } else {
                    //case3 , left branch
                    cparent->color = BLACK;
                    gparent->color = RED;
                    left_rotation(rb, gparent);
                }  
            }
        }
    }

    rb->root->color = BLACK;
}

//transplant
//this function is very simple, just decide the direction and change the pointer
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

//
void rb_deletion(tree *rb, int n){
    //deletion process

    //fix up process
}

void rb_deletion_fix(tree *rb, int n){

}


//pre order
void pretty_print(link p, int indent)
{
    if(p != NULL) {
        /*if(indent) {*/
            /*for (int i = 0; i < indent; ++i)*/
            /*{*/
                /*printf(" ");*/
            /*}*/
        /*}*/
        printf("%d\n", p->val);
        printf("color is: %s\n", (p->color == 1? "black":"red"));
        /*printf("\n");*/
        if(p->left) {
            pretty_print(p->left, indent-1);
        }
        
        if(p->right) {
            pretty_print(p->right, indent+1);
        }
    }
}
