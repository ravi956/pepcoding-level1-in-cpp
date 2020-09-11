#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &v, int k)
{
    int n = v.size();
    k = k % n;
    int start = (k >= 0) ? n - k : -k;
    start %= n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = v[start];
        start = (start + 1) % n;
    }
    v = temp;
}

void display(vector<int> &v)
{
    for (int val : v)
        cout << val << " ";
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> k;
    rotate(v, k);
    display(v);
    return 0;
}