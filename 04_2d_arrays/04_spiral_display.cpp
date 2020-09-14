#include <iostream>
using namespace std;

void print(int *arr[], int n, int m)
{
    int top = 0, right = m - 1, bottom = n - 1, left = 0;
    int total = n * m;
    int count = 0;
    while (count < total)
    {
        for (int j = left, i = top; i <= bottom && count < total; i++)
        {
            cout << arr[i][j] << endl;
            count++;
        }
        left++;
        for (int i = bottom, j = left; j <= right && count < total; j++)
        {
            cout << arr[i][j] << endl;
            count++;
        }
        bottom--;
        for (int j = right, i = bottom; i >= top && count < total; i--)
        {
            cout << arr[i][j] << endl;
            count++;
        }
        right--;
        for (int i = top, j = right; j >= left && count < total; j--)
        {
            cout << arr[i][j] << endl;
            count++;
        }
        top++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    print(arr, n, m);
    return 0;
}