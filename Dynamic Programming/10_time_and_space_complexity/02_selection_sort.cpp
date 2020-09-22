#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isSmaller(int arr[], int i, int j)
{
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    return (arr[i] < arr[j]);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (isSmaller(arr, j, m))
            {
                m = j;
            }
        }
        swap(arr, i, m);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr, n);
    print(arr, n);
}