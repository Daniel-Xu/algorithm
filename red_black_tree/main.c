#include <stdio.h>
#include "red_black_tree.h"


int main(int argc, char const *argv[])
{
    tree *rb = new_tree();
    /*int a[] = {6, 2, 10, 3, 1, 7, 8, 9};*/
    /*int a[] = {6, 2, 10, 3, 1, 7};*/
    int a[] = {12, 1, 9, 2, 0, 11, 7, 19, 4, 15, 18, 5, 14, 13, 10, 16, 6, 3, 8, 17};
    for (int i = 0; i < 20; ++i)
    {
        rb_insertion(rb, a[i]);
        /*pretty_print(rb->root, 1); */
        /*printf("+++++++++++++++++++++\n");*/
    }
    /*printf("%d\n", sizeof(rb));*/
    printf("root is: \n");
    printf("%d\n", rb->root->val);
    pretty_print(rb->root, 1); 

    /*printf("post order result is: \n");*/
    /*pretty_print(rb->root, 10);*/

    /*link min = rb_minimum(rb->root);*/
    /*link max = rb_maximum(rb->root);*/

    /*printf("min is: %d, max is:  %d\n", min->val, max->val);*/
    
}
