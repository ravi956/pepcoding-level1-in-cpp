#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> bpath;
        bpath.push_back("");
        return bpath;
    }
    vector<string> hpath;
    vector<string> vpath;

    if (sc < dc)
    {
        hpath = getMazePaths(sr, sc + 1, dr, dc);
    }
    if (sr < dr)
    {
        vpath = getMazePaths(sr + 1, sc, dr, dc);
    }
    vector<string> path;

    for (string s : hpath)
    {
        path.push_back('h' + s);
    }
    for (string s : vpath)
    {
        path.push_back('v' + s);
    }
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> res = getMazePaths(1, 1, n, m);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
}