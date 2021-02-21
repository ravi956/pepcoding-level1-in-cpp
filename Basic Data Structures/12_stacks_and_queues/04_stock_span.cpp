#include <bits/stdc++.h>
using namespace std;

void spanCalc(int a[], int span[], int n)
{
    stack<int> s;
    span[0] = 1;
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && a[s.top()] <= a[i])
            s.pop();

        span[i] = s.empty() ? i + 1 : i - s.top();

        s.push(i);
    }
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int span[n];
    spanCalc(a, span, n);

    for (int i = 0; i < n; i++)
        cout << span[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}