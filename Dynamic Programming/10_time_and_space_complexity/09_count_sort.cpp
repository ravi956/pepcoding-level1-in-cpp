#include <bits/stdc++.h>
using namespace std;

void countSort(int *arr, int min, int max, int n)
{
    int range = max - min + 1;
    int farr[range] = {0};

    for (int i = 0; i < n; i++)
    {
        int idx = arr[i] - min;
        farr[idx]++;
    }

    for (int i = 1; i < range; i++)
        farr[i] += farr[i - 1];

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = farr[val - min];
        int idx = pos - 1;
        ans[idx] = val;
        farr[val - min]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
        minimum = min(minimum, arr[i]);
    }
    countSort(arr, minimum, maximum, n);
    print(arr, n);
    return 0;
}