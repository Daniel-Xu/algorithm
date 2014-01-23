#include <iostream>
#include <vector>
using namespace std;

int count(int n, vector<int> &map)
{
    if (n == 0) {
        return 1;
    } else if(n < 0) {
        return 0; 
    } else if(map[n] > -1) {
        return map[n];
    } else {
        return map[n] = count(n-1, map) + count(n-2, map) + count(n-3, map);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> map(100, -1);
    int i = count(3, map); 
   
    cout << i  << endl;
    return 0;
}
