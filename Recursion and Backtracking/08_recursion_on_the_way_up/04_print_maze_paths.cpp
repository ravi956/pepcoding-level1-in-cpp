#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

    if (sc < dc)
    {
        printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    }
    if (sr < dr)
    {
        printMazePaths(sr + 1, sc, dr, dc, psf + "v");
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    printMazePaths(1, 1, n, m, "");
    return 0;
}