#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    //mpist -> max profit if sold today
    //lsf -> least so far
    //dpl -> dp max profit if sold upto today (left side)
    int mpist = 0;
    int lsf = prices[0];
    int dpl[n] = {0};
    for (int i = 1; i < n; i++)
    {
        lsf = min(lsf, prices[i]);
        mpist = prices[i] - lsf;
        dpl[i] = max(mpist, dpl[i - 1]);
    }

    //mpibt -> max profit if bought today
    //maxat -> max after today
    //dpr -> dp max profit if bought today or after (right side)
    int mpibt = 0;
    int maxat = prices[n - 1];
    int dpr[n] = {0};
    for (int i = n - 2; i >= 0; i--)
    {
        maxat = max(maxat, prices[i]);
        mpibt = maxat - prices[i];
        dpr[i] = max(mpibt, dpr[i + 1]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        maxProfit = max(maxProfit, dpl[i] + dpr[i]);
    }
    cout << maxProfit;
    return 0;
}