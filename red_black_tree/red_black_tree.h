#ifndef RED_BLACK_TREE_H_XEX90NU3
#define RED_BLACK_TREE_H_XEX90NU3RED_BLACK_TREE_H_XEX90NU3

enum color_type { RED, BLACK };

typedef struct node{ 
  int val;
  enum color_type color;
  struct node *parent;
  struct node *left;
  struct node *right;
}node, *link;

typedef struct tree {
    link root;
}tree;

//declaration

tree *new_tree(void);
void pretty_print(link p, int indent);

void rb_insertion_fix(tree *rb, link x);


#endif /* end of include guard: RED_BLACK_TREE_H_XEX90NU3RED_BLACK_TREE_H_XEX90NU3 */
