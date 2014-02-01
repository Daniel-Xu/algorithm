#include <iostream>
#include<string>
using namespace std;
string reverse(string s)
{
    if(s.size() == 1) {
        return s;
    } else {
        return s[s.size()-1] + reverse(s.substr(0, s.size()-1));
    }
}

int main(int argc, char const *argv[])
{
    string s("helloworld");

    cout << reverse(s) << endl;
    return 0;
}
