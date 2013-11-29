#include <iostream>
#include <unordered_map>

using namespace std;

#define N 5
#define M 2

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

link init(int a[], int n, int m)
{
  link head, p, q;
  for (int i = 0; i < n; ++i)
  {
    // this syntax should be familiar 
    link nd = new node();
    nd->val = a[i];
    if(i == m)
      q = nd;
    if (i == 0)
    {
      p = head = nd;
      continue;
    }

    p->next = nd;
    p = nd;
  }
  p->next = q; 

  return head;
}

link make_node(int val)
{
  link p = new node();
  p->val = val;
  p->next = NULL;
  
  return p;
}

link circleStart(link head)
{
  if(head == NULL) return NULL;

  unordered_map<link, bool> address;

  while(head) {
    if (address[head]) return head;
    else {
      address[head] = true;
      head = head->next;
    }
  }
  
  return head;
}

int main(int argc, char const *argv[])
{
  int a[] = {2, 3, 2, 4, 1};
  link a_p  = init(a, N, M);

  cout << "original list a is: " << endl;
  //print_link(a_p);

  cout << "the start of the circle's data is: " << circleStart(a_p)->val << endl;
    
  return 0;
}
