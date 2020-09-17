#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int minr = 0, minc = 0, maxr = n - 1, maxc = n - 1;
    while (minc < n)
    {
        int i = minr, j = minc;
        while (i <= maxr && j <= maxc)
        {
            cout << arr[i][j] << endl;
            i++;
            j++;
        }
        minc++;
        maxr--;
    }
    return 0;
}