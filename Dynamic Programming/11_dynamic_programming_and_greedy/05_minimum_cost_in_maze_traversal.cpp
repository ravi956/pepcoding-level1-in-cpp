#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = arr[i][j];
            else if (i == n - 1)
                dp[i][j] = arr[i][j] + dp[i][j + 1];
            else if (j == m - 1)
                dp[i][j] = arr[i][j] + dp[i + 1][j];
            else
                dp[i][j] = arr[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[0][0];
    return 0;
}