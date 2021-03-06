#include <iostream>

using namespace std;

#define N 5
#define M 5

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

link make_node(int val)
{
  link p = new node();
  p->val = val;
  p->next = NULL;
  
  return p;
}


//this is a normal version
link add2(link a, link b)
{
  link p = a;
  link q = b;
  link new_link = NULL;
  link current_p = NULL;

  int sum = 0;
  int current_v = 0;
  int next_v = 0;

  //next v can only be 0 or 1
  while(p != NULL && q != NULL){
    sum = p->val + q->val + next_v;
    current_v = sum%10;
    next_v = sum/10;

    if(new_link == NULL) {
      current_p = new_link = make_node(current_v);
    }
    else {
      current_p->next = make_node(current_v);
      current_p = current_p->next;
    }
    p = p->next;
    q = q->next;
  }

  //new method

  while (p != NULL) {
    sum = p->val + next_v;
    next_v = sum/10;
    current_v = sum%10;

    current_p->next = make_node(current_v);

    current_p = current_p->next;
    p = p->next;
  }

  while (q != NULL) {
    sum = q->val + next_v;
    next_v = sum/10;
    current_v = sum%10;

    current_p->next = make_node(current_v);

    current_p = current_p->next;
    q = q->next;
  }

  if (p == NULL && q == NULL && next_v != 0) {
    current_p->next = make_node(next_v);
    current_p->next->next = NULL;
  }

  return new_link;
}



// as we all see, normal version is too messy
// so we need to implement recusive version


int main(int argc, char const *argv[])
{
  int a[] = {2, 3, 2, 4, 1};
  int b[] = {3, 5, 10, 6, 2};
  link a_p  = init(a, N);
  link b_p = init(b, M);

  cout << "original list a is: " << endl;
  print_link(a_p);
  cout << "original list b is: " << endl;
  print_link(b_p);


  cout << "add a and b: " << endl;
  print_link(add2(a_p, b_p));
  
  return 0;
}
