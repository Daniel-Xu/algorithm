#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {2, 4, 3, 5, 1, 7, 6, 9, 8};
    int tmp[9];
    int index[9];

    memset(tmp, 0, sizeof(int)*9);
    memset(index, -1, sizeof(int)*9);

    tmp[0] = 1;
    int max;
    int max_j = 0;
    int index_j = 0;

    for (int j = 0; j < 9; ++j)
    {
        max = 0;

        for (int i = 0; i < j; ++i)
        {
            if(a[j] >= a[i] && tmp[i] > max){
                max = tmp[i];
                index[j] = i;
            }
            
        }
        tmp[j] = max+1;

        if(tmp[j] > max_j){
            index_j = j;
            max_j = tmp[j];
        }
    }

    cout << "result is: " << max_j <<endl; 


    
    while(index[index_j] != -1) {
        cout << a[index_j] << "\t"; 
        index_j = index[index_j];
    }
    cout << a[index_j] <<endl;

    return 0;
}
