#include <bits/stdc++.h>
using namespace std;

int *mergeTwoSortedArrays(int a[], int b[], int n, int m)
{
    int *arr = new int[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while (i < n)
    {
        arr[k++] = a[i++];
    }
    while (j < m)
    {
        arr[k++] = b[j++];
    }
    return arr;
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int *mergedArray = mergeTwoSortedArrays(a, b, n, m);
    print(mergedArray, n + m);
    return 0;
}