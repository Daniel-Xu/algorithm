#include <stdio.h>

int fib_ultimate(int n)
{
    int back2 = 0;
    int back1 = 1;
    int next;

    
    if (n==0)
        return 0;

    for (int i = 2; i < n; ++i)
    {
        int next = back2 + back1;
        back2 = back1;
        back1 = next;
    }

    return(back2+back1);
}

int main(int argc, char const *argv[])
{
    
    printf("%d\n", fib_ultimate(6)); 
    return 0;
}
