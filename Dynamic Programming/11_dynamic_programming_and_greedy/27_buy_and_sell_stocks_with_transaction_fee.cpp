#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fee;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cin >> fee;

    //bsp -> boughtStateProfit i.e one stock is in hand
    //ssp -> soldStateProfit i.e no stock is in hand
    int bsp = -prices[0];
    int ssp = 0;

    for (int i = 1; i < n; i++)
    {
        int newbsp = max(bsp, ssp - prices[i]);
        int newssp = max(ssp, prices[i] + bsp - fee);
        bsp = newbsp;
        ssp = newssp;
    }
    cout << ssp;
    return 0;
}