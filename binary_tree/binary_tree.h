#ifndef BINARY_TREE_H_ZOTJNHAX
#define BINARY_TREE_H_ZOTJNHAX


typedef struct node{
  int val;
  struct node* left;
  struct node* right;
}node, *link;

//declare
link init_tree(int inorder[], int preorder[], int num);
void post_order(link t, void (*visit)(link));
void pre_order(link t, void (*visit)(link));
void in_order(link t, void (*visit)(link));
int node_num(link t);
void destroy(link t);
#endif /* end of include guard: BINARY_TREE_H_ZOTJNHAX */


