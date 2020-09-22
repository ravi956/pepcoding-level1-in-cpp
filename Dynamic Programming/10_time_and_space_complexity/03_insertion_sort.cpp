#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isGreater(int arr[], int j, int i)
{
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    return (arr[i] < arr[j]);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (isGreater(arr, j, j + 1))
            {
                swap(arr, j, j + 1);
            }
            else
            {
                break;
            }
        }
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
    insertionSort(arr, n);
    print(arr, n);
}