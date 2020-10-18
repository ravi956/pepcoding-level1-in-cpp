#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long same = k * 1;
    long diff = k * (k - 1);
    long total = same + diff;

    for (int i = 3; i <= n; i++)
    {
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }

    cout << total;
    return 0;
}