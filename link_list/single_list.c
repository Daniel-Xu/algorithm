//create link
#include <stdlib.h>
#include <stdio.h>
#include "single_list.h"


link create_single_list()
{
  link head, p, s;
  int x;
  scanf("%d", &x);
  if(x != -1) {
    head = malloc(sizeof(node));
    head -> val = x;
    head -> next = NULL;
    s = head;
  } else{
    return NULL;
  }

  while(1) {
    scanf("%d", &x);
    if(x == -1) 
      break;
    p = malloc(sizeof(node));
    p->val = x;
    p->next = NULL;
    s->next = p; 
    s = p;
  }

  return head;
}

//print link
void print_link(link t)
{
  while(t != NULL) {
    printf("%d\t", t->val); 
    t = t->next;
  }

  printf("\n");
}

//delete node
//head  middle end 
link delete_node(link t, int num)
{
  link p, q, head = t; 
  p = t;
  while(p->val != num && p->next != NULL){
    q = p; 
    p = p->next;  
  }
  
  if(num == p->val){
    if(p == t){
      head = head->next;
    } else {
      q->next = p->next;
    }

    free(p);
  }else{
    printf("Could not find the node\n"); 
  }

  return head;
}

//reverse single link  in place
link reverse_link(link t)
{
  link p = t, q, s;
  q = p->next;

  while(q != NULL) {
    s = q->next;
    q->next = p;
    p = q;
    q = s;
  }
  t->next =NULL; 

  return p;
}
