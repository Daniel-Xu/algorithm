#include <iostream>

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

link findLastK(link a, int k)
{
  if ( a == NULL || k <= 0)
    return NULL;

  link p, q;  
  p = q = a;

  while(k-- > 0) {
    q = q->next;
  }

  while(q != NULL) {
    p = p->next;
    q = q->next;  
  }

  return p;
}

int main(int argc, char const *argv[])
{
  int a[] = {1, 3, 4, 5, 6, 7, 8, 0};
  link head = init(a, 8);
  print_link(head);
  
  int k;
  cout << "please input the length you want" << endl;
  cin >> k;
  link dst = findLastK(head, k);
  cout << "the result is: " << endl;
  print_link(dst);
  return 0;
}
