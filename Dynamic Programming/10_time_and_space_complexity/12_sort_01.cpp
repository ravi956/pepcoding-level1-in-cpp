#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j)
{
    cout << "Swapping index " << i << " and index " << j << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort01(int *arr, int n)
{
    int i = 0, j = 0;
    while (i < n)
    {
        if (arr[i] <= 0)
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
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n, pivot;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> pivot;
    sort01(arr, n);
    print(arr, n);
    return 0;
}