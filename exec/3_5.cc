#include <iostream>
#include <stack>

using namespace std;

#define N 10
template <typename T>

class MyQueue{
public:
  MyQueue(){
  
  }

  //deconstructor   
  ~MyQueue(){
     
  }

  void push(T val){
    sin.push(val);
  }

  //pop 
  void pop(){
      move(sin, sout);
      sout.pop();
  }

  T front(){
      move(sin, sout);
      return sout.top();
  }

  T back(){
    move(sout, sin);
    return sin.top();
  }

  int size(){
    return sin.size() + sout.size(); 
  }

  bool empty(){
    return (sin.empty() && sout.empty());
  }

  void move(stack<T> &src, stack<T> &dst){
    if (dst.empty()) {
      while (!src.empty()) {
        dst.push(src.top());
        src.pop();
      }
    }
  }

private:
  stack<T> sin, sout;
};

int main(int argc, char const *argv[])
{
  MyQueue<int> q;


  for (int i = 1; i < N; ++i)
  {
    q.push(i);
  }

  cout << "1 2 3 4 5 6 7 8 9" <<endl;
  cout << "front is: " << q.front() << endl;
  cout << "end is: " << q.back() <<endl;

  q.pop();
  q.push(20);

  cout << "after pop and push front is: " << q.front() <<endl;
  cout << "after pop and push end is: " << q.back() <<endl;

  return 0;
}
