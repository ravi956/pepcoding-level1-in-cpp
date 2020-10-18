#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long ob = 1;
    long os = 1;

    for (int i = 2; i <= n; i++)
    {
        long nb = os;
        long ns = os + ob;

        os = ns;
        ob = nb;
    }

    long total = os + ob;
    total = total * total;
    cout << total;
    return 0;
}