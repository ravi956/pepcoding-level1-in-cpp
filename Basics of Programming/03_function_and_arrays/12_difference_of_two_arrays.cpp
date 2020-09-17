#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    vector<int> res(n2);
    n1--;
    n2--;
    int carry = 0;
    while (n1 >= 0)
    {
        int d1 = arr1[n1--];
        int d2 = arr2[n2];
        int c = d2 - d1 + carry;
        if (c < 0)
        {
            c += 10;
            carry = -1;
        }
        else
            carry = 0;
        res[n2--] = c;
    }
    while (n2 >= 0)
    {
        int c = arr2[n2] + carry;
        if (c < 0)
        {
            c += 10;
            carry = -1;
        }
        else
            carry = 0;
        res[n2--] = c;
    }
    if (res[0] != 0)
        cout << res[0] << endl;
    for (int i = 1; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}