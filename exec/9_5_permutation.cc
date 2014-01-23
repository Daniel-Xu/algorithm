#include <iostream>
#include <vector>
#include <string>

using namespace std;
//ab
//ab ba

//abc
//abc acb bac bca cab cba

typedef vector<string> vs;

//we can use top down, choose one charactor from abc, and remain characters do permutaion()
vs permutation(string src)
{
    vs result;

    if(src == "") {
        result.push_back("");
        return result;
    }

    for (int i = 0; i < src.size(); ++i)
    {
        string c = src.substr(i, 1);
        //leap of faith, I believe permutation will return what I want
        //every time vs the loop body elapses, the res will dispear
        string tmp = src;
        vs res = permutation(tmp.erase(i, 1));
        for (int i = 0; i < res.size(); ++i)
        {
            result.push_back(c+res[i]);
        }  
    }

    return result;
}

int main(int argc, char const *argv[])
{
    
    vs result;
    string a("abc");
    result = permutation(a);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }


    return 0;
}
