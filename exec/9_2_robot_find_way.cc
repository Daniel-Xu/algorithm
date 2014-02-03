#include <iostream>
using namespace std;

//length
#define X 3
#define Y 3 

//x is start, y is end
void find_path(int x, int y, int *count) 
{
    if(x==X && y == Y){
        (*count)++;
        return;
    }

    if( x < X){
        find_path(x+1, y, count);
    }

    if(y < Y) {
        find_path(x, y+1, count);
    }
}


int main(int argc, char const *argv[])
{
    int c = 0;

    find_path(0, 0, &c);
    cout << c<< endl;
    

    return 0;
}
