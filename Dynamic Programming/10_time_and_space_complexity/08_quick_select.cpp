#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int pivot, int lo, int hi)
{
    cout << "pivot -> " << pivot << endl;
    int i = lo, j = lo;
    while (i <= hi)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << "pivot index -> " << (j - 1) << endl;
    return (j - 1);
}

int quickSelect(int *arr, int lo, int hi, int k)
{
    int pivot = arr[hi];
    int pi = partition(arr, pivot, lo, hi);
    if (k < pi)
    {
        return quickSelect(arr, lo, pi - 1, k);
    }
    else if (k > pi)
    {
        return quickSelect(arr, pi + 1, hi, k);
    }
    else
    {
        return pivot;
    }
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << quickSelect(arr, 0, n - 1, k - 1);
    return 0;
}