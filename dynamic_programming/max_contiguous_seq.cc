#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int a[] = {-2, 11, -4, 13, -5, 2};
    int start = 0;
    int end = 0;
    int runningSum = a[0];
    int max = 0;
    int j = 0;


    //we use DP to solve the problem
    //M(j) refers to the max contiguous seq which end at j. 
    //if we know the M(j-1) + a[j] > a[j], then M(j) = M(j-1) + a[j]
    //else the M(j) = a[j]
    //
    //then we choose the max of M(1..n)

    for(int i = 1; i < sizeof(a)/4; i++) {
        //int tmp = runningSum + a[i];
        //we can optimize it
        if(runningSum > 0)
            runningSum += a[i];
        else {
            runningSum = a[i];
            j = i;
        }

        if(runningSum > max){
            max = runningSum;
            start = j;
            end = i;
        }

    }
    
    cout << "the result is: " << max << endl;
    cout << "the start is: " << a[start] << endl;
    cout << "the end is: " << a[end] << endl;
    
    return 0;
}
