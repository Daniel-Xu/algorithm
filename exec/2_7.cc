#include <iostream>
#include <stack>

using namespace std;


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


bool isPalindrome(link a) 
{

  link fast = a;
  link slow = a;
  stack<int> reverse;

  while(fast != NULL && fast->next != NULL) {
    reverse.push(slow->val);
    slow = slow->next;
    fast = fast->next->next;
  } 
    
  if(fast != NULL) 
    slow = slow->next;
  
  while(slow != NULL) {
    if(slow->val != reverse.top()) {
      return false;
    }
    slow = slow->next;
    reverse.pop();
  }

  return true;
}

int main(int argc, char const *argv[])
{
  
  int a[] = {1};
  link head = init(a,1);
  cout << "the link is:" << endl;
  print_link(head);

  if (isPalindrome(head))
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
}
