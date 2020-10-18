#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (i < j || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }

    cout << dp[n][k];
    return 0;
}