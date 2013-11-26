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

//recursive version
//we can use a return parameter
void findLastKRecurse(link a, int k, link* pos) 
{
  //static is also very useful in this situation
  static int i = k;
  if(a == NULL)
    return;

  findLastKRecurse(a->next, k, pos);
  if(i == 1) 
    *pos = a;
  --i;
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
  link p;
  cout << "please input the length you want" << endl;
  cin >> k;
  //link dst = findLastK(head, k);
  findLastKRecurse(head, k, &p);

  cout << "the result is: " << endl;
  //print_link(dst);
  print_link(p);
  return 0;
}
