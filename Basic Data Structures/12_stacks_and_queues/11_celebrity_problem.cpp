#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    stack<int> celeb;
    celeb.push(0);

    for (int i = 1; i < n; i++)
    {
        int p1 = celeb.top();
        celeb.pop();
        int p2 = i;
        if (arr[p1][p2] == 1)
        {
            celeb.push(p2);
        }
        else
        {
            celeb.push(p1);
        }
    }

    int celebCandi = celeb.top();
    for (int i = 0; i < n; i++)
    {
        if (i != celebCandi)
        {
            if (arr[celebCandi][i] == 1 || arr[i][celebCandi] == 0)
            {
                cout << "none\n";
                return;
            }
        }
    }
    cout << celebCandi << "\n";
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