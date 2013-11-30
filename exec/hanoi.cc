#include <iostream>
using namespace std;
class Hanoi
{
public:
  Hanoi(int len):totalNum(len){

  }
  
  ~Hanoi(){}

  void solve(){
    string src = "A";
    string tmp = "B";
    string dst = "C";

    move(totalNum, src, tmp, dst);
  }
private:
  int totalNum;
  void moveOne(string src, string dst) {
    cout << "move from " << src << "to " << dst << endl;
  }
  
  void move(int num, string src, string tmp, string dst) {
    if (num == 1) {
      moveOne(src, dst);
    } else {
      move(num-1, src, dst, tmp);
      moveOne(src, dst);
      move(num-1, tmp, src, dst);
    }
  }
};

int main(int argc, char const *argv[])
{
  Hanoi hanoi(3);
  
  hanoi.solve();
  return 0;
}
