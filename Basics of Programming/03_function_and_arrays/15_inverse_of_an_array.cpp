#include <bits/stdc++.h>
using namespace std;

vector<int> inverse(vector<int> v)
{
    int n = v.size();
    vector<int> inv(n);
    for (int i = 0; i < n; i++)
        inv[v[i]] = i;
    return inv;
}

void display(vector<int> v)
{
    for (int val : v)
        cout << val << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> inv = inverse(v);
    display(inv);
    return 0;
}