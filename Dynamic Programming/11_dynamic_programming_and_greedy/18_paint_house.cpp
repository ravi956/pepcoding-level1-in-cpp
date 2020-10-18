#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    int r = arr[0][0];
    int b = arr[0][1];
    int g = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        int nr = arr[i][0] + min(b, g);
        int nb = arr[i][1] + min(r, g);
        int ng = arr[i][2] + min(r, b);

        r = nr;
        b = nb;
        g = ng;
    }

    int minCost = min({r, b, g});
    cout << minCost;
    return 0;
}