#include <iostream>
using namespace std;

int need_count(int a, int b)
{
    int count = 0;
    for (int c = a^b; c != 0; c = c & (c-1))
    {
        count++;
    }
    return count;
}


int main(int argc, char const *argv[])
{
    cout << need_count(31,14) << endl;
    
    return 0;
}
