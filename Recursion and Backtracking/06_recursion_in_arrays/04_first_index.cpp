#include <iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n)
{
    if (idx == n)
    {
        return -1;
    }
    if (arr[idx] == x)
        return idx;
    else
        return firstIndex(arr, idx + 1, x, n);
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << firstIndex(arr, 0, x, n);
    return 0;
}