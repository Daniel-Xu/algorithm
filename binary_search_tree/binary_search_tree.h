#ifndef BINARY_SEARCH_TREE_H_BFKVTIXN
#define BINARY_SEARCH_TREE_H_BFKVTIXN

typedef struct node{ 
  int val;
  struct node *parent;
  struct node *left;
  struct node *right;
}node, *link;

typedef struct tree {
    link root;
}tree;



//declaration

tree *new_tree(void);

void bst_insert(tree *bst, int i);

void transplant_subtree(tree *bst, link u, link v);

void bst_delete(tree *bst, int i);

link bst_minimum(link x);

link bst_successor(link x);

link bst_maximum(link x);

link bst_search(tree *bst, int i);

void pretty_print(link p, int indent);
#endif /* end of include guard: BINARY_SEARCH_TREE_H_BFKVTIXN */

