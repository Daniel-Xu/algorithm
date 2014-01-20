#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int w[3] = {20, 10, 12};
    int v[3] = {5, 4, 3};
    int capacity = 10;
    int num = 3;
    int d[4][11];

    for (int i = 0; i <= num; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            d[i][j] = i==0? 0: d[i-1][j];
            int yes_i = d[i-1][j-v[i-1]]+w[i-1];
            if(i > 0 && j >= v[i-1]) 
                d[i][j] = d[i][j]>yes_i? d[i][j]:yes_i;
        }
    }    

    printf("%d\n", d[3][10]);

    return 0;
}
