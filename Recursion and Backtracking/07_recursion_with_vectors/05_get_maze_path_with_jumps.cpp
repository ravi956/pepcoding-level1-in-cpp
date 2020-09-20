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

    vector<string> paths;

    //horizontal moves
    for (int ms = 1; ms <= dc - sc; ms++)
    {
        vector<string> hpaths = getMazePaths(sr, sc + ms, dr, dc);
        for (string hpath : hpaths)
        {
            paths.push_back("h" + to_string(ms) + hpath);
        }
    }

    //vertical moves
    for (int ms = 1; ms <= dr - sr; ms++)
    {
        vector<string> vpaths = getMazePaths(sr + ms, sc, dr, dc);
        for (string vpath : vpaths)
        {
            paths.push_back("v" + to_string(ms) + vpath);
        }
    }

    //diagonal moves
    int maxDmoves = (dc - sc) < (dr - sr) ? (dc - sc) : (dr - sr);
    for (int ms = 1; ms <= maxDmoves; ms++)
    {
        vector<string> dpaths = getMazePaths(sr + ms, sc + ms, dr, dc);
        for (string dpath : dpaths)
        {
            paths.push_back("d" + to_string(ms) + dpath);
        }
    }
    return paths;
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