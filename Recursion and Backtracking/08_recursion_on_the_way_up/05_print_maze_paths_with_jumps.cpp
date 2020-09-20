#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

    //horizontal moves
    for (int ms = 1; ms <= dc - sc; ms++)
    {
        printMazePaths(sr, sc + ms, dr, dc, psf + "h" + to_string(ms));
    }

    //vertical moves
    for (int ms = 1; ms <= dr - sr; ms++)
    {
        printMazePaths(sr + ms, sc, dr, dc, psf + "v" + to_string(ms));
    }

    //diagonal moves
    int maxDmoves = (dc - sc) < (dr - sr) ? (dc - sc) : (dr - sr);
    for (int ms = 1; ms <= maxDmoves; ms++)
    {
        printMazePaths(sr + ms, sc + ms, dr, dc, psf + "d" + to_string(ms));
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    printMazePaths(1, 1, n, m, "");
    return 0;
}