#include <bits/stdc++.h>
using namespace std;

vector<string> gss(string str)
{
    if (str.length() == 0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch = str[0];
    string ros = str.substr(1);
    vector<string> rres = gss(ros);

    vector<string> mres;
    for (string s : rres)
        mres.push_back("" + s);
    for (string s : rres)
        mres.push_back(ch + s);
    return mres;
}

int main()
{
    string str;
    cin >> str;
    vector<string> res = gss(str);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}