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
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= amt; j++)
            dp[j] += dp[j - arr[i]];
    }

    cout << dp[amt] << endl;
    return 0;
}