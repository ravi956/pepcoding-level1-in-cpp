#include <bits/stdc++.h>
using namespace std;

int chess[10000][10000];

void displayBoard(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printKnightsTour(int r, int c, int move, int n)
{
    if (r < 0 || c < 0 || r >= n || c >= n || chess[r][c] > 0)
    {
        return;
    }
    else if (move == n * n)
    {
        chess[r][c] = move;
        displayBoard(n);
        chess[r][c] = 0;
        return;
    }

    chess[r][c] = move;
    printKnightsTour(r - 2, c + 1, move + 1, n);
    printKnightsTour(r - 1, c + 2, move + 1, n);
    printKnightsTour(r + 1, c + 2, move + 1, n);
    printKnightsTour(r + 2, c + 1, move + 1, n);
    printKnightsTour(r + 2, c - 1, move + 1, n);
    printKnightsTour(r + 1, c - 2, move + 1, n);
    printKnightsTour(r - 1, c - 2, move + 1, n);
    printKnightsTour(r - 2, c - 1, move + 1, n);
    chess[r][c] = 0;
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;

    printKnightsTour(r, c, 1, n);

    return 0;
}