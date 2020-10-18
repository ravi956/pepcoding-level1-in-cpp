#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cap;
    cin >> n;
    int val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int wts[n];
    for (int i = 0; i < n; i++)
        cin >> wts[i];
    cin >> cap;

    vector<pair<double, int>> valPerWt(n);
    for (int i = 0; i < n; i++)
    {
        valPerWt[i] = {(double)val[i] / wts[i], wts[i]};
    }

    sort(valPerWt.begin(), valPerWt.end(), greater<>());

    double maxVal = 0;
    for (int i = 0; cap > 0; i++)
    {
        int wtAdded = min(valPerWt[i].second, cap);
        maxVal += wtAdded * valPerWt[i].first;
        cap -= wtAdded;
    }

    cout << maxVal;
    if (floor(maxVal) == maxVal)
        cout << ".0";
    return 0;
}