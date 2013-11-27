#include <iostream>

using namespace std;
#define N 10


typedef struct node {
  int val;
  struct node *next;
}node, *link; 

using namespace std;


void print_link(link a)
{
  link p = a;
  while(p != NULL) {
    cout << p->val << "\t";
    p = p->next;
  }

  cout << endl;
}

link init(int a[], int n)
{
  link head, p;
  for (int i = 0; i < n; ++i)
  {
    // this syntax should be familiar 
    link nd = new node();
    nd->val = a[i];
    if (i == 0)
    {
      p = head = nd;
      continue;
    }

    p->next = nd;
    p = nd;
  }
  p->next = NULL; 

  return head;
}

//this is not completed version
//because the x_node isn't deleted.
link partition(link a, int x)
{
  // travse the link list
  link p; 
  link q;

  if(a == NULL)
    return NULL;
 
  // make a new node x, make it as head
  link x_node = new node();
  x_node->val = x;
  x_node->next = a;
  link head = x_node; 
  p = q = x_node;

  while(p != NULL) {
    if(p->val < x){
      q->next = p->next;
      p->next = head;
      head = p;
      p = q->next;

    } else {
      q = p;
      p = p->next;
    }
  }
  q->next = NULL;
    
  return head;

}

//better version

link partition2(link a, int x)
{
  link less = NULL;
  link more = NULL;

  link p = a;
  while(p != NULL) {
    link q = p->next;
    if(p->val < x) {
      p->next = less;
      less = p;
    } else {
      p->next = more; 
      more = p;
    }
    //let p go next
    p = q;
  }

  //if all the element are larger than x
  if(less == NULL)
    return more;

  link head = less;
  //find last one of less;
  while(less->next != NULL) {
    less = less->next;
  }

  less->next = more;

  return head;
}


int main(int argc, char const *argv[])
{
  
  int a[] = {5, 1, 2, 3, 7, 0, 9, 2, 1, 8};
  link head = init(a,N);
  cout << "the link is:" << endl;
  print_link(head);

  cout << "after inserting" <<endl;

  print_link(partition2(head, 6));

  return 0;
}
