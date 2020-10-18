#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            int minimum = INT_MAX;
            for (int j = 1; j <= arr[i] && i + j < n + 1; j++)
            {
                if (dp[i + j] != -1)
                {
                    minimum = min(minimum, dp[i + j]);
                }
            }
            if (minimum != INT_MAX)
            {
                dp[i] = 1 + minimum;
            }
        }
    }

    if (dp[0] == -1)
        cout << "null";
    else
        cout << dp[0];
}