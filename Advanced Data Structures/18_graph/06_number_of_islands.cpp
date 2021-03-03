#include <bits/stdc++.h>
using namespace std;

int arr[10000][10000];
bool visited[10000][10000];

void drawTreeForComponent(int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || arr[i][j] == 1 || visited[i][j] == true)
    {
        return;
    }

    visited[i][j] = true;

    drawTreeForComponent(i - 1, j, m, n);
    drawTreeForComponent(i, j + 1, m, n);
    drawTreeForComponent(i, j - 1, m, n);
    drawTreeForComponent(i + 1, j, m, n);
}

int main()
{
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && visited[i][j] == false)
            {
                drawTreeForComponent(i, j, m, n);
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}