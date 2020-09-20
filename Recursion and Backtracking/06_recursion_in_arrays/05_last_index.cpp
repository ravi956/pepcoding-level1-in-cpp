#include <bits/stdc++.h>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n)
{
    if (idx == n)
    {
        return -1;
    }
    int last = lastIndex(arr, idx + 1, x, n);
    if (last != -1)
    {
        return last;
    }
    else if (arr[idx] == x)
    {
        return idx;
    }
    else
    {
        return -1;
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
    cout << lastIndex(arr, 0, x, n);
    return 0;
}