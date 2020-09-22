#include <bits/stdc++.h>
using namespace std;

void printTargetSumPair(int *arr, int n, int target)
{
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << arr[i] << ", " << arr[j] << endl;
            i++;
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    int n, target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> target;
    printTargetSumPair(arr, n, target);
    return 0;
}