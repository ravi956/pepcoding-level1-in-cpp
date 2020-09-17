#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int marks;
    cin >> marks;
    if (marks > 90)
        cout << "excellent";
    else if (marks > 80)
        cout << "good";
    else if (marks > 70)
        cout << "fair";
    else if (marks > 60)
        cout << "meets expectations";
    else
        cout << "below par";
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