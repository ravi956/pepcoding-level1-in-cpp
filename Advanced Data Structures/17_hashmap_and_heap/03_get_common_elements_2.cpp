#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    unordered_map<int, int> hm;
    for (int i = 0; i < n1; i++)
    {
        int a;
        cin >> a;
        hm[a]++;
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int a;
        cin >> a;

        if (hm.find(a) != hm.end())
        {
            if (hm[a] > 0)
            {
                cout << a << "\n";
                hm[a]--;
            }
            else
            {
                hm.erase(a);
            }
        }
    }

    return 0;
}