#include <stdio.h>
#include "red_black_tree.h"


int main(int argc, char const *argv[])
{
    tree *rb = new_tree();
    int a[] = {6, 2, 10, 3, 1, 7, 8, 9, 4};
    for (int i = 0; i < 9 ; ++i)
    {
        rb_insertion(rb, a[i]);
    }
    /*printf("%d\n", sizeof(rb));*/
    printf("root is: \n");
    printf("%d\n", rb->root->val);

    /*printf("post order result is: \n");*/
    pretty_print(rb->root, 10);

    /*link min = rb_minimum(rb->root);*/
    /*link max = rb_maximum(rb->root);*/

    /*printf("min is: %d, max is:  %d\n", min->val, max->val);*/
    
}
