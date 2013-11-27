#include <iostream>
#include <unordered_map>

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

//no buffer can use
//the complexity is O(n*n)
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

//hash table
//the complexity is O(N)
link removeRepition2(link a)
{
  link p = a;
  link q = a->next;

  //pair key value
  pair<int, bool> first_element (p->val, true);
  unordered_map<int, bool> hash;
  hash.insert(first_element);
     
  while(q != NULL) {
    if(hash.find(q->val) != hash.end()) {
      //find it
      p->next = q->next;
      delete q;
      q = p->next;
    } else {
      hash.insert(make_pair<int, bool>(q->val, true));
      p = q;
      q = q->next;
    }
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
  print_link(removeRepition2(head));
  
  return 0;
}
