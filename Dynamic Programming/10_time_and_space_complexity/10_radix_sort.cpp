#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countSort(int *arr, int exp, int n)
{
    int farr[10] = {0};

    for (int i = 0; i < n; i++)
        farr[arr[i] / exp % 10]++;

    for (int i = 1; i < 10; i++)
        farr[i] += farr[i - 1];

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = farr[arr[i] / exp % 10];
        int idx = pos - 1;
        ans[idx] = val;
        farr[arr[i] / exp % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];

    cout << "After sorting on " << exp << " place -> ";
    print(arr, n);
}

void radixSort(int *arr, int n)
{
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
        maximum = max(maximum, arr[i]);

    int exp = 1;
    while (exp <= maximum)
    {
        countSort(arr, exp, n);
        exp = exp * 10;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    radixSort(arr, n);
    print(arr, n);
}