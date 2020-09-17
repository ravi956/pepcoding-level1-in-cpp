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

    int n = (n1 > n2) ? n1 : n2;
    vector<int> res(n);
    n1--;
    n2--;
    n--;
    int carry = 0;
    while (n1 >= 0 && n2 >= 0)
    {
        int d1 = arr1[n1--];
        int d2 = arr2[n2--];
        int c = d1 + d2 + carry;
        res[n--] = c % 10;
        carry = c / 10;
    }
    while (n1 >= 0)
    {
        int c = arr1[n1--] + carry;
        res[n--] = c % 10;
        carry = c / 10;
    }
    while (n2 >= 0)
    {
        int c = arr2[n2--] + carry;
        res[n--] = c % 10;
        carry = c / 10;
    }
    if (carry != 0)
        cout << carry << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}