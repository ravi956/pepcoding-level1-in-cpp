#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    unordered_map<int, bool> hm;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hm[arr[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (hm.find(arr[i] - 1) != hm.end())
        {
            hm[arr[i]] = false;
        }
    }

    int start = 0;
    int max_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (hm[arr[i]])
        {
            int count = 1;
            while (hm.find(arr[i] + count) != hm.end())
            {
                count++;
            }
            if (count > max_count)
            {
                start = arr[i];
                max_count = count;
            }
        }
    }

    for (int i = 0; i < max_count; i++)
    {
        cout << start + i << "\n";
    }

    return 0;
}