#include <iostream>
#include <string>

using namespace std;

//basestatement is: length is 0 or 1
//statement change: from the middle to outside 
bool palindrome(string s)
{   
    if(s.size() == 0)
        return true;
    else if(s.size() == 1)
        return true;
    else if(s.size() == 2)
        return s[0] == s[1];

    bool res = palindrome(s.substr(1, s.size()-2));
    if(res && s[0] == s[s.size()-1])
        return true;
    else 
        return false;
}

int main(int argc, char const *argv[])
{
    string s1("aibohphobia");
    string s2("livenotonevil");
    string s3("abc");
    string s4("ced");

    cout << s1 << "is: " <<  palindrome(s1) << endl;
    cout << s2 << "is: " <<  palindrome(s2) << endl;
    cout << s3 << "is: " <<  palindrome(s3) << endl;
    cout << s4 << "is: " <<  palindrome(s4) << endl;
    
    return 0;
}
