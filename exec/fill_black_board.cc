#include <iostream>
using namespace std;

int c[4];
int num = 4;

void color_count(int n, int *count)
{

    if (n == num) {
        for (int i = 0; i < num; ++i)
        {
            cout << c[i] << " ";
        }
        cout << endl;
        (*count)++;
        return;
    }
        
    for (int i = 0; i < 2; ++i)
    {
        c[n] = i;
        int flag = 1;

        if(n >= 2 && c[n-1] == c[n] && c[n-2] == c[n]){
            flag = 0;
        }

        if(flag)
            color_count(n+1, count);

    }

}

int main(int argc, char const *argv[])
{
    
    int count = 0;

    cout << "original" << endl;
    for (int i = 0; i < num; ++i)
    {
        cout<< c[i] << "  ";
    }
    cout << endl;
    color_count(0, &count);
    cout << "count is: " << count <<endl;
    return 0;
}
