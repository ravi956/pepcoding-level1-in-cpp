#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            pq.push(arr[i]);
        }
        else
        {
            cout << pq.top() << "\n";
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (pq.size() > 0)
    {
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}