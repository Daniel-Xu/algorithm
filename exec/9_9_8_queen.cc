#include <iostream>
using namespace std;


int c[20];
int n = 8;

void print_queen()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(j == c[i])
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    cout << endl;
}
//r is the line, from 0 - 7 line
void queen(int r, int *count)
{
    if(r == n) {
        print_queen();
        (*count)++;
        return;    
    }

    //r line, i column
    for (int i = 0; i < n; ++i)
    {
        c[r] = i;
        int flag = 1;
        //to test the correctness
        //the same colum, same diagonal 
        for (int j = 0; j < r; ++j)
        {
            if(c[j] == c[r] || r-j == c[r]-c[j] || r-j == c[j]-c[r]) {
                flag = 0; 
                break;
            }
        }

        if(flag) 
            queen(r+1, count);
    }
}

int main(int argc, char const *argv[])
{
    
    int count = 0;
    queen(0, &count);
    cout << "method number: " << count << endl;
    return 0;
}
