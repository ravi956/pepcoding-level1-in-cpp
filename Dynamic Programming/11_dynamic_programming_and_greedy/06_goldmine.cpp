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
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == m - 1)
                dp[i][j] = arr[i][j];
            else if (i == 0)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            else if (i == n - 1)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            else
                dp[i][j] = arr[i][j] + max({dp[i - 1][j + 1], dp[i][j + 1], dp[i + 1][j + 1]});
        }
    }

    int maxGold = INT_MIN;
    for (int i = 0, j = 0; i < n; i++)
        maxGold = max(maxGold, dp[i][j]);

    cout << maxGold;
    return 0;
}