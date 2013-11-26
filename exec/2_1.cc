#include <iostream>

using namespace std;

#define N 5

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

link removeRepition(link a)
{
  link p = a;

  while(p != NULL) {
    link s = p;
    link q = p->next;

    while(q != NULL){
      if(s->val == q->val) {
        p->next = q->next; 
        free(q);
        q = p->next;
      } else {
        p = p->next;
        q = q->next; 
      }
    }

    p = s->next;
  }

  return a;
}

int main(int argc, char const *argv[])
{
  int a[] = {2,  3, 2, 4, 2};
  link head = init(a, N);
  cout << "original list is: " << endl;
  print_link(head);

  cout << "delete repitition: " << endl;
  print_link(removeRepition(head));
  
  return 0;
}
