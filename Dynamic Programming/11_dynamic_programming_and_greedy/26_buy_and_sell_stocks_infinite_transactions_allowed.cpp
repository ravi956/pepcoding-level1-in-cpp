#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int totalProfit = 0;
    int bd = 0;
    int sd = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] >= prices[i - 1])
        {
            sd++;
        }
        else
        {
            totalProfit += prices[sd] - prices[bd];
            bd = sd = i;
        }
    }

    totalProfit += prices[sd] - prices[bd];

    cout << totalProfit;
    return 0;
}