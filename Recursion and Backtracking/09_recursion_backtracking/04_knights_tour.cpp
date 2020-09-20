#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> &chess)
{
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess[0].size(); j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess, int row, int col, int move)
{
    if (row < 0 || row >= chess.size() || col < 0 || col >= chess.size() || chess[row][col] > 0)
    {
        return;
    }
    if (move == (chess.size() * chess.size()))
    {
        chess[row][col] = move;
        displayBoard(chess);
        chess[row][col] = 0;
        return;
    }

    chess[row][col] = move;
    printKnightsTour(chess, row - 2, col + 1, move + 1);
    printKnightsTour(chess, row - 1, col + 2, move + 1);
    printKnightsTour(chess, row + 1, col + 2, move + 1);
    printKnightsTour(chess, row + 2, col + 1, move + 1);
    printKnightsTour(chess, row + 2, col - 1, move + 1);
    printKnightsTour(chess, row + 1, col - 2, move + 1);
    printKnightsTour(chess, row - 1, col - 2, move + 1);
    printKnightsTour(chess, row - 2, col - 1, move + 1);
    chess[row][col] = 0;
}

int main()
{
    int n, row, col;
    cin >> n >> row >> col;
    vector<vector<int>> chess;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n, 0);
        chess.push_back(temp);
    }
    printKnightsTour(chess, row, col, 1);
    return 0;
}