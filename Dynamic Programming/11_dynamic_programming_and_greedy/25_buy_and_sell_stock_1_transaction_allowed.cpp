#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int lsf = INT_MAX;
    int maxProfit = 0;
    int profitToday = 0;

    for (int i = 0; i < n; i++)
    {
        lsf = min(lsf, prices[i]);
        profitToday = prices[i] - lsf;
        maxProfit = max(maxProfit, profitToday);
    }

    cout << maxProfit;
    return 0;
}