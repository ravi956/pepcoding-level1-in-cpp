#include <iostream>
#include <algorithm>
using namespace std;

void print(int *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

//rotate the matrix by 90 Deg anticlockwise
void rotate(int *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = n - 1;
        while (left < right)
        {
            swap(arr[i][left], arr[i][right]);
            left++;
            right--;
        }
    }
    print(arr, n);
}

int main()
{
    int n;
    cin >> n;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    rotate(arr, n);
    return 0;
}