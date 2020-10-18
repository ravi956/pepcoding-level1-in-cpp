#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // int dp0[n + 1];
    // int dp1[n + 1];

    // dp0[1] = 1;
    // dp1[1] = 1;

    // for (int i = 2; i <= n; i++)
    // {
    //     dp0[i] = dp1[i - 1];
    //     dp1[i] = dp0[i - 1] + dp1[i - 1];
    // }
    // cout << dp0[n] + dp1[n];

    int oczeros = 1;
    int ocones = 1;

    for (int i = 2; i <= n; i++)
    {
        int nczeros = ocones;
        int ncones = oczeros + ocones;
        oczeros = nczeros;
        ocones = ncones;
    }
    cout << oczeros + ocones;
    return 0;
}