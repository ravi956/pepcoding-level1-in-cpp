#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

void display(vector<int> &v)
{
    for (int val : v)
        cout << val << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    reverse(v);
    display(v);
    return 0;
}