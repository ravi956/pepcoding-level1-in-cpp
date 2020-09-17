#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    for (int i = maximum; i >= 1; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= i)
                cout << "*\t";
            else
                cout << "\t";
        }
        cout << endl;
    }

    return 0;
}