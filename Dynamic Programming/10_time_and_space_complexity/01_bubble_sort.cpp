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

void bubbleSort(int arr[], int n)
{
    for (int itr = 0; itr < n - 1; itr++)
    {
        for (int j = 1; j < n - itr; j++)
        {
            if (isSmaller(arr, j, j - 1))
            {
                swap(arr, j, j - 1);
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
    bubbleSort(arr, n);
    print(arr, n);
}