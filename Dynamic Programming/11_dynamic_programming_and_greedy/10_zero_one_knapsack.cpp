#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cap;
    cin >> n;

    int vals[n], wts[n];

    for (int i = 0; i < n; i++)
        cin >> vals[i];

    for (int i = 0; i < n; i++)
        cin >> wts[i];

    cin >> cap;

    int dp[n + 1][cap + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j >= wts[i - 1])
            {
                int rCap = j - wts[i - 1];
                if (dp[i - 1][rCap] + vals[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][rCap] + vals[i - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][cap];
    return 0;
}