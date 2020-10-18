#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    int arr[n][c];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int dp[n][c];
    int least1 = INT_MAX;
    int least2 = INT_MAX;
    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];

        if (dp[0][j] <= least1)
        {
            least2 = least1;
            least1 = dp[0][j];
        }
        else if (dp[0][j] <= least2)
        {
            least2 = dp[0][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        int nleast1 = INT_MAX;
        int nleast2 = INT_MAX;
        for (int j = 0; j < c; j++)
        {
            int mn = (dp[i - 1][j] != least1) ? least1 : least2;

            dp[i][j] = arr[i][j] + mn;

            if (dp[i][j] <= nleast1)
            {
                nleast2 = nleast1;
                nleast1 = dp[i][j];
            }
            else if (dp[i][j] <= nleast2)
            {
                nleast2 = dp[i][j];
            }
        }
        least1 = nleast1;
        least2 = nleast2;
    }

    cout << least1;
    return 0;
}