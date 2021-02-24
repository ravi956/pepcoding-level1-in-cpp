#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    unordered_map<char, int> hm;

    for (char c : str)
    {
        hm[c]++;
    }

    char ans;
    int max_count = 0;

    for (auto x : hm)
    {
        if (x.second > max_count)
        {
            ans = x.first;
            max_count = x.second;
        }
    }

    cout << ans;
    return 0;
}