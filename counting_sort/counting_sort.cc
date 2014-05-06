#include <iostream>
using namespace std;


int put_array(int a[], int size)
{
    for (int i = 0; i < size ; ++i)
    {
        cout << a[i] << "\t";
    }

    cout << endl;
    return 0;
}

int counting_sort(int a[], int b[], int k, int a_len)
{
    int range[k+1];

    //clear c
    fill_n(range, k+1, 0);
    
    //cal c
    for (int i = 0; i < a_len; ++i)
    {
        range[a[i]] = range[a[i]] +1;
    }

    //cal num before a[i]
    for (int i = 1; i <= k; ++i)
    {
        range[i] += range[i-1];
    }

    for (int i = a_len-1; i>= 0; --i)
    {
        b[range[a[i]]-1] = a[i];
        range[a[i]] -= 1;
    }

    put_array(b, a_len);

    return 0;
}


int max_value(int a[], int size)
{
    int max_v = a[0];

    for (int i = 1; i < size; ++i)
    {
        if(a[i] > max_v)
            max_v = a[i];
    }
    return max_v;
}

int main(int argc, char const *argv[])
{
    
    int a[] = {3, 5, 4, 7, 2, 6, 9, 19, 12, 23, 11, 9, 3};

    int a_len = sizeof(a)/sizeof(int);
    int a_max = max_value(a, a_len);


    put_array(a, a_len);
    
    int b[a_len];
    fill_n(b, a_len, 0);

    counting_sort(a, b, a_max, a_len);

    return 0;
}
