#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int w[3] = {20, 10, 12};
    int v[3] = {5, 4, 3};
    int capacity = 10;
    int num = 3;
    int d[4][11];
    int gem_detail[3] = {0, 0, 0};

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

    int j = capacity;
    for (int i = num; i > 0; --i)
    {
        if(d[i][j] > d[i-1][j]) {
            gem_detail[i-1] = 1;
            j = capacity-v[i-1];
        }
    }

    printf("%d\n", d[3][10]);

    for (int i = 0; i < num; ++i)
    {
        printf("%d\n", gem_detail[i]);
    }

    return 0;
}
