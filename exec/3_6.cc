#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;
stack<int> TwoStackSort(stack<int> s)
{
  stack<int> t;
  while(!s.empty()) {
    int a = s.top(); 
    s.pop();

    //move the bigger data to the bottom in s
    while( !t.empty() && t.top() > a){
      s.push(t.top());
      t.pop();
    }
    t.push(a);
  }

  return t;
}

//priority queue usage
void Qsort(stack<int> &s)
{
  //how to use this
  priority_queue< int, vector<int>, greater<int> > q;

  while( !s.empty()){
    q.push(s.top());
    s.pop();
  }

  while(!q.empty()) {
    s.push(q.top());
    q.pop();
  }
}

int main(int argc, char const *argv[])
{

  srand((unsigned)time(NULL));
  stack<int> src;
  
  for (int i = 0; i < 10; ++i)
  {
    src.push(rand()%100);
  }  

  //src = TwoStackSort(src);
  Qsort(src);

  cout << "after sorting" <<endl;
  while(!src.empty()){
    cout << src.top() << "\t"; 
    src.pop();
  }
  cout << endl;

  return 0;
}
