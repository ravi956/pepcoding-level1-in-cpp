#include <bits/stdc++.h>
using namespace std;

bool isItaSafePlaceForTheQueen(vector<vector<int>> &chess, int row, int col)
{
    for (int i = row - 1, j = col; i >= 0; i--)
        if (chess[i][j] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (chess[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
        if (chess[i][j] == 1)
            return false;

    return true;
}

void printNQueens(vector<vector<int>> &chess, string qsf, int row)
{
    if (row == chess.size())
    {
        cout << qsf + "." << endl;
        return;
    }

    for (int col = 0; col < chess.size(); col++)
    {
        if (isItaSafePlaceForTheQueen(chess, row, col) == true)
        {
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n, 0);
        chess.push_back(temp);
    }
    printNQueens(chess, "", 0);
    return 0;
}