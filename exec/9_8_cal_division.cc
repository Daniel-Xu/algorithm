#include <iostream>
using namespace std;


int cal(int n, int div)
{
    int next_div = 0;

    switch(div) {
        case 25:
            next_div = 10;
            break;
        case 10:
            next_div = 5;
            break;
        case 5:
            next_div = 1;
            break;

        case 1:
            return 1;
    }


    int ways = 0;
    for (int i = 0; i*div < n; ++i)
    {
        ways += cal(n - i*div, next_div);
    }

    return ways;
}

int main(int argc, char const *argv[])
{
    cout << "Total methods are: " << cal(14, 25) << endl;
    return 0;
}
