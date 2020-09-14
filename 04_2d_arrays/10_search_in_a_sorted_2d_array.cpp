#include <bits/stdc++.h>
using namespace std;

void search(vector<vector<int>> v, int x)
{
    int n = v.size();
    if (x < v[0][0] || x > v[n - 1][n - 1])
    {
        cout << "Not Found";
        return;
    };
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (x == v[i][j])
        {
            cout << i << endl;
            cout << j;
            return;
        }
        else if (x < v[i][j])
            j--;
        else
            i++;
    }
    cout << "Not Found";
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }
    int x;
    cin >> x;
    search(v, x);
    return 0;
}