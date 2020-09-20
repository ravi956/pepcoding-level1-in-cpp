#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    if (n == 0)
        return;
    fun(n - 1);
    cout << n << endl;
}

void solve()
{
    int n;
    cin >> n;
    fun(n);
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