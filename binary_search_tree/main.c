#include <stdio.h>
#include "binary_search_tree.h"


int main(int argc, char const *argv[])
{
    tree *bst = new_tree();
    int a[] = {6, 2, 10, 3, 1, 7, 8, 9, 4};
    for (int i = 0; i < 9 ; ++i)
    {
        bst_insert(bst, a[i]);
    }
    /*printf("%d\n", sizeof(bst));*/
    printf("root is: \n");
    printf("%d\n", bst->root->val);

    printf("post order result is: \n");
    pretty_print(bst->root, 10);

    link min = bst_minimum(bst->root);
    link max = bst_maximum(bst->root);

    printf("min is: %d, max is:  %d\n", min->val, max->val);
    
    
    bst_delete(bst, 2);
    pretty_print(bst->root, 10);
}
