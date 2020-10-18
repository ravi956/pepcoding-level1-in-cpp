#include <iostream>
using namespace std;

int countPaths(int n, int qb[]) //Memoization
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    if (qb[n] != 0)
    {
        return qb[n];
    }

    int nm1 = countPaths(n - 1, qb);
    int nm2 = countPaths(n - 2, qb);
    int nm3 = countPaths(n - 3, qb);
    int cp = nm1 + nm2 + nm3;

    qb[n] = cp;
    return cp;
}

int countPathsTab(int n) //Tabulation
{
    int dp[n + 1];

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            dp[i] = dp[i - 1];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    // int qb[n + 1] = {0};
    // int cp = countPaths(n, qb);
    int cp = countPathsTab(n);
    cout << cp << endl;
    return 0;
}