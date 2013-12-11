#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPer1(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    //quick sort two string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2 ) 
        return true;
    else
        return false;
}

bool isPer2(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int c[256];
    memset(c, 0, sizeof(c));

    int len = str1.length();
    for (int i = 0; i < len; ++i)
    {
        ++c[(int)str1[i]];
        --c[(int)str2[i]];
    }

    for (int i = 0; i < 256; ++i)
    {
        if(c[i] != 0)
            return false;
    }

    return true;
}


int main(int argc, char const *argv[])
{

    string str1, str2;
    cout << "please input string1" << endl;
    cin >> str1;
    cout << "please input string2" << endl;
    cin >> str2; 


    if(isPer2(str1, str2)) 
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

