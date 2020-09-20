#include <bits/stdc++.h>
using namespace std;

vector<string> getStairPaths(int n)
{
    if (n == 0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    else if (n < 0)
    {
        vector<string> bres;
        return bres;
    }

    vector<string> prePath1 = getStairPaths(n - 1);
    vector<string> prePath2 = getStairPaths(n - 2);
    vector<string> prePath3 = getStairPaths(n - 3);
    vector<string> mres;

    for (string s : prePath1)
    {
        mres.push_back("1" + s);
    }
    for (string s : prePath2)
    {
        mres.push_back("2" + s);
    }
    for (string s : prePath3)
    {
        mres.push_back("3" + s);
    }
    return mres;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = getStairPaths(n);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
}