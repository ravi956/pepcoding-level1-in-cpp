#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amt;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> amt;

    int dp[amt + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= amt; i++)
    {
        for (int j = 0; j < n; j++)
            if (arr[j] <= i)
                dp[i] += dp[i - arr[j]];
    }

    cout << dp[amt] << endl;
    return 0;
}