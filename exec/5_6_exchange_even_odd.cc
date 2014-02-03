#include <iostream> 
using namespace std;

int exchange(int a)
{
    return  ((x & 0x55555555) << 1) | ((x>>1) & 0x55555555);
}
