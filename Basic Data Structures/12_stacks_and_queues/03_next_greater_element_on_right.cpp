#include <bits/stdc++.h>
using namespace std;

void printNextGreater(int arr[], int res[], int n)
{
    stack<int> s;
    res[n - 1] = -1;
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res[n];
    printNextGreater(arr, res, n);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}