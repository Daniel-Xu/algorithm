#include <iostream>

using namespace std;
//if a[i] > i, then a[x] > x if x>i
//if a[i] < i, then a[x] < x if x<i
//int magic_index(int a[], int start, int end)
//{
    //while(start <= end){
        //int mid = (start+end)/2;
        //if(a[mid] > mid)
            //end = mid-1;
        //else if(a[mid] < mid)
            //start = mid+1;
        //else
            //return mid;
    //}

    //return -1;
//}

int magic_index(int a[], int start, int end, int len)
{
    if(start < 0 || end >= len || start > end)
        return -1;

    int mid = (start+end)/2;

    if(a[mid] > mid)
        return magic_index(a, start, mid-1,len);
    else if(a[mid] < mid)
        return magic_index(a, mid+1, end, len);
    else 
        return mid;
}

int main(int argc, char const *argv[])
{
    int a[] = {-1, 1, 3, 4,5};

    cout << magic_index(a, 0, 4, 5) <<endl;
    return 0;
}
