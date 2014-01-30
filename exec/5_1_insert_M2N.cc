#include <iostream>
using namespace std;

int insert(int n, int m, int j, int i)
{
    int allone = ~0;
    int left = allone << (j+1);
    int right = (1 << i) -1;
    int mask = left|right;
    n = n&mask;

    m = m << i;

    n = n | m;

    return n;
}
