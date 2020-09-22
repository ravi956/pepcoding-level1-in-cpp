#include <bits/stdc++.h>
using namespace std;

int findPivot(int *arr, int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[high])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return arr[low];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pivot = findPivot(arr, n);
    cout << pivot << endl;
    return 0;
}