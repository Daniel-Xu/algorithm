#ifndef SINGLE_LINK_H_KR5XG84G
#define SINGLE_LINK_H_KR5XG84GSINGLE_LINK_H_KR5XG84G

typedef struct node{
  int val;
  struct node *next;
}node, *link;


//declare

link create_single_list();

void print_link(link t);

link delete_node(link t, int num);

link reverse_link(link t);

#endif /* end of include guard: SINGLE_LINK_H_KR5XG84GSINGLE_LINK_H_KR5XG84G */

