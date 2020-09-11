#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int answer = 0;
    int base = 1;
    while (n > 0)
    {
        answer += (int)pow(10, (n % 10) - 1) * base;
        base++;
        n /= 10;
    }
    cout << answer;
    return 0;
}