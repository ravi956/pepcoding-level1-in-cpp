#include <bits/stdc++.h>
using namespace std;

void reverse(int oned[], int l, int r)
{
    while (l < r)
    {
        swap(oned[l], oned[r]);
        l++;
        r--;
    }
}

void rotate(int oned[], int sz, int r)
{
    r = r % sz;
    if (r < 0)
    {
        r += sz;
    }
    reverse(oned, 0, sz - r - 1);
    reverse(oned, sz - r, sz - 1);
    reverse(oned, 0, sz - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int s, r;
    cin >> s >> r;

    //fillOnedFromShell
    int minr = s - 1;
    int minc = s - 1;
    int maxr = n - s;
    int maxc = m - s;
    int sz = 2 * (maxr - minr + maxc - minc);

    int oned[sz];
    int idx = 0;

    //left
    for (int i = minr, j = minc; i <= maxr; i++)
        oned[idx++] = arr[i][j];
    //bottom
    for (int i = maxr, j = minc + 1; j <= maxc; j++)
        oned[idx++] = arr[i][j];
    //right
    for (int i = maxr - 1, j = maxc; i >= minr; i--)
        oned[idx++] = arr[i][j];
    //top
    for (int i = minr, j = maxc - 1; j >= minc + 1; j--)
        oned[idx++] = arr[i][j];

    rotate(oned, sz, r);

    //fillShellFromOned
    idx = 0;
    //left
    for (int i = minr, j = minc; i <= maxr; i++)
        arr[i][j] = oned[idx++];

    //bottom
    for (int i = maxr, j = minc + 1; j <= maxc; j++)
        arr[i][j] = oned[idx++];

    //right
    for (int i = maxr - 1, j = maxc; i >= minr; i--)
        arr[i][j] = oned[idx++];

    //top
    for (int i = minr, j = maxc - 1; j >= minc + 1; j--)
        arr[i][j] = oned[idx++];

    //display
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}