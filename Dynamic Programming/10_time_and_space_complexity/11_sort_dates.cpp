#include <bits/stdc++.h>
using namespace std;

void countSort(string *arr, int div, int mod, int range, int n)
{
    // write your code here
    string ans[n];
    int farr[range] = {0};

    for (int i = 0; i < n; i++)
    {
        int idx = stoi(arr[i]) / div % mod;
        farr[idx]++;
    }

    for (int i = 1; i < range; i++)
    {
        farr[i] += farr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int num = stoi(arr[i]);
        int pos = farr[num / div % mod] - 1;
        ans[pos] = arr[i];
        farr[num / div % mod]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

void sortDates(string *arr, int n)
{
    countSort(arr, 1000000, 100, 32, n); //days
    countSort(arr, 10000, 100, 13, n);   //months
    countSort(arr, 1, 10000, 2501, n);   //years
}

void print(string *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortDates(arr, n);
    print(arr, n);
    return 0;
}