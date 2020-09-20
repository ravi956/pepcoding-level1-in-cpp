#include <bits/stdc++.h>
using namespace std;
vector<string> key = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> kpc(string str)
{
    if (str.length() == 0)
    {
        vector<string> bexp;
        bexp.push_back("");
        return bexp;
    }

    int k = stoi(str.substr(0, 1));
    vector<string> faith = kpc(str.substr(1));
    vector<string> exp;
    for (char c : key[k])
    {
        for (string s : faith)
        {
            exp.push_back(c + s);
        }
    }
    return exp;
}

int main()
{
    string str;
    cin >> str;
    vector<string> res = kpc(str);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
}