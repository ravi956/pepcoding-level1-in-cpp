#include <bits/stdc++.h>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, t1id, t3id, t2id);
    cout << n << "[" << t1id << " -> " << t2id << "]" << endl;
    toh(n - 1, t3id, t2id, t1id);
}

void solve()
{
    int n, n1, n2, n3;
    cin >> n >> n1 >> n2 >> n3;
    toh(n, n1, n2, n3);
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