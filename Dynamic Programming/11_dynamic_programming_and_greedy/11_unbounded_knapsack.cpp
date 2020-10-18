#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cap;
    cin >> n;
    int val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int wts[n];
    for (int i = 0; i < n; i++)
        cin >> wts[i];
    cin >> cap;

    int dp[cap + 1] = {0};
    for (int i = 1; i <= cap; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wts[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - wts[j]] + val[j]);
            }
        }
    }
    cout << dp[cap];
    return 0;
}