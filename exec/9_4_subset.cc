#include <iostream>
#include <vector>

using namespace std;


typedef vector< vector<int> > vvi;
typedef vector<int> vi;

vvi get_subset(vi &src)
{
    vvi result;

    if(src.empty()){
        result.push_back(src);
        return result;
    }
    vi tmp = src;
    int start = *tmp.begin();
    tmp.erase(tmp.begin());
    vvi res = get_subset(tmp);

    for (int i = 0; i < res.size(); ++i)
    {
        vi set = res[i];
        result.push_back(set);
        set.insert(set.begin(), start);
        result.push_back(set);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vi a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    vvi b = get_subset(a);

    for (int i = 0; i < b.size(); ++i)
    {
        for (int j = 0; j < b[i].size(); ++j)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
