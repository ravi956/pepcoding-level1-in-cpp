#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cin >> k;

    int dp[k + 1][n];
    memset(dp, 0, sizeof(dp));

    for (int t = 1; t <= k; t++)
    {
        int maximum = INT_MIN;
        for (int d = 1; d < n; d++)
        {
            maximum = max(maximum, dp[t - 1][d - 1] - prices[d - 1]);
            dp[t][d] = max(dp[t][d - 1], maximum + prices[d]);
        }
    }

    cout << dp[k][n - 1];
    return 0;
}