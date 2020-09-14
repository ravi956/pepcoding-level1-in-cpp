#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    char move;
    if (arr[0][0] == 0)
        move = 'R';
    else
        move = 'D';
    int i = 0, j = 0;
    while (true)
    {
        if (arr[i][j] == 1)
        {
            if (move == 'D')
                move = 'L';
            else if (move == 'U')
                move = 'R';
            else if (move == 'R')
                move = 'D';
            else if (move == 'L')
                move = 'U';
        }
        switch (move)
        {
        case 'D':
        {
            i++;
            break;
        }
        case 'U':
        {
            i--;
            break;
        }
        case 'R':
        {
            j++;
            break;
        }
        case 'L':
        {
            j--;
            break;
        }
        }
        if (i == n)
        {
            i--;
            break;
        }
        else if (j == m)
        {
            j--;
            break;
        }
        else if (i == -1)
        {
            i++;
            break;
        }
        else if (j == -1)
        {
            j++;
            break;
        }
    }
    cout << i << endl;
    cout << j << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}