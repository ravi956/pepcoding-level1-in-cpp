#include <bits/stdc++.h>
using namespace std;

int maxOfArray(int arr[], int idx, int n)
{
    if (idx == n)
        return INT_MIN;
    int max1 = maxOfArray(arr, idx + 1, n);
    if (arr[idx] > max1)
        return arr[idx];
    else
        return max1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxOfArray(arr, 0, n);
    return 0;
}