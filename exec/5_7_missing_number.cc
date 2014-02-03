//1 2 1 3 1 2 1 4 12 1 3 1 2 1 5
//it's a recursive process

// 2^2 -> 2+1 = 3
// 7%2 == 1 -> 1
// 6 = 3*2^1 -> 1+1 = 2

#include <iostream>
using namespace std;

bool check_number(int a[], int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if(i%2 != 0) {
            check(i%2);
        } else {
            if(i && (i-1) == 0) {
                //2^j
                check(j+1);
            } else {
                //i % 2== 0 
                int n = 0;
                while(i%2 == 0) {
                    i /= 2;
                    n++;
                }
                check(n++);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    check() 
    return 0;
}
