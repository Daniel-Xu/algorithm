#include <iostream>
#include <stack>

using namespace std;
#define N 4 


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

// I think link* is a return pointer.
// why the return parameter's type is link*, rather than link
// because the next value is local variable in the current stack
// so if you want to return it, you should return its adress.
bool isPalindromeRecurse(link a, int len, link *next)
{
  if(a == NULL || len == 0){  //invalid link list
    return false; 
  }else if(len == 1) { // length != 0 && a != NULL, odd length
    *next = a->next;
    return true; 
  }else if(len == 2) { // even length
    *next = a->next->next;
    return a->val == a->next->val; 
  }
  
  // this is the middle stack return val
  bool res = isPalindromeRecurse(a->next, len-2, next);
  
  // this is stack return, determine the front and end
  // end address is in the next 
  // front is the head, i.e. a
  if(res == false) {
    return res;
  } else {
    res = a->val == (*next)->val;
    *next = a->next;
    return res;
  }
}


int main(int argc, char const *argv[])
{
  
  int a[] = {2, 2,2, 1};
  link head = init(a,N);
  cout << "the link is:" << endl;
  print_link(head);

  link next;
  if (isPalindromeRecurse(head, N, &next))
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
}
