#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    int arr1[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
            cin >> arr1[i][j];
    }
    cin >> n2 >> m2;
    int arr2[n2][m2];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
            cin >> arr2[i][j];
    }
    if (m1 != n2)
    {
        cout << "Invalid Input";
        return;
    }
    int arr3[n1][m2];
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            arr3[i][j] = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m1; k++)
                arr3[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}