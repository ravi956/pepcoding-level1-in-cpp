#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    //bsp -> boughtStateProfit i.e one stock is in hand
    //ssp -> soldStateProfit i.e no stock is in hand
    //csp -> cooldownStateProfit i.e no stock in hand and one day gap after selling
    int bsp = -prices[0];
    int ssp = 0;
    int csp = 0;

    for (int i = 1; i < n; i++)
    {
        int newbsp = max(bsp, csp - prices[i]);
        int newssp = max(ssp, bsp + prices[i]);
        int newcsp = max(csp, ssp);
        bsp = newbsp;
        ssp = newssp;
        csp = newcsp;
    }
    cout << ssp;
    return 0;
}