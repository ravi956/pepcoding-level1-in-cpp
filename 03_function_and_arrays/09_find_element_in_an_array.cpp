#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == d)
            index = i;
    }
    cout << index << endl;
    return 0;
}