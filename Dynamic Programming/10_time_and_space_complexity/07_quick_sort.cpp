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

void quickSort(int *arr, int lo, int hi)
{
    if (lo <= hi)
    {
        int pi = partition(arr, arr[hi], lo, hi);
        quickSort(arr, lo, pi - 1);
        quickSort(arr, pi + 1, hi);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}