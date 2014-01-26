#include <iostream>
using namespace std;


void print_pare(int left, int right, char a[], int len)
{
    if(left < 0 || right < 0) 
        return;

    if(left == 0 && right == 0) {
        for (int i = 0; i <len; ++i)
        {
            cout << a[i];
        }
        cout << endl;
    } else {
        if(left > 0) {
            a[len] = '(';
            print_pare(left-1, right, a, len+1);
        }
    
        if(right > left){
            a[len] = ')';
            print_pare(left, right-1, a, len+1);
        }
    }

}
int main(){
    int cnt = 3;
    char str[2*cnt];
    print_pare(cnt, cnt, str, 0);
    return 0;
}

