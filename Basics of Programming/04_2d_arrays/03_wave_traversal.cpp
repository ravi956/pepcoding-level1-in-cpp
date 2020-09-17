#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int r, c;
    cin >> r >> c;
    int arr[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    for (int j = 0; j < c; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < r; i++)
                cout << arr[i][j] << endl;
        }
        else
        {
            for (int i = r - 1; i >= 0; i--)
                cout << arr[i][j] << endl;
        }
    }
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