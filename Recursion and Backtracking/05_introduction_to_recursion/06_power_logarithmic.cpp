#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 1;
    int temp = power(x, n / 2);
    int ans = temp * temp;
    if (n % 2 == 1)
        ans *= x;
    return ans;
}

void solve()
{
    int x, n;
    cin >> x >> n;
    cout << power(x, n);
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