#include <bits/stdc++.h>
using namespace std;
int sz = 0;

int *allIndices(int *arr, int x, int idx, int fsf, int n)
{
    if (idx == n)
    {
        return new int[fsf];
    }

    if (arr[idx] == x)
    {
        sz++;
        int *iarr = allIndices(arr, x, idx + 1, fsf + 1, n);
        iarr[fsf] = idx;
        return iarr;
    }
    else
    {
        int *iarr = allIndices(arr, x, idx + 1, fsf, n);
        return iarr;
    }
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    int *iarr = allIndices(arr, x, 0, 0, n);
    if (sz == 0)
    {
        cout << endl;
    }
    else
    {
        for (int i = 0; i < sz; i++)
            cout << iarr[i] << endl;
    }
    return 0;
}