#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b > a)
        swap(a, b);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << " ";
    cout << lcm(num1, num2);
    return 0;
}
