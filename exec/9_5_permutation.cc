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

vs permutation_insert(string src)
{
    vs result;

    if(src == ""){
        result.push_back("");
        return result; 
    }

    string c = src.substr(0, 1);
    string tmp = src;
    vs res = permutation_insert(tmp.erase(0, 1));
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j <= res[i].size();++j)
        {
            string u = res[i];
            string p = u.insert(j, c);
            result.push_back(p);
        }
    }
    return result;
}




int main(int argc, char const *argv[])
{
    
    vs result;
    string a("a");
    result = permutation_insert(a);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }


    return 0;
}
