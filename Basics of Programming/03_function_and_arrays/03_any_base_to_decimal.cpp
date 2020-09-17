#include <iostream>
using namespace std;

int solve(int n, int b)
{
    int res = 0;
    int mult = 1;
    while (n != 0)
    {
        res += (n % 10) * mult;
        mult *= b;
        n /= 10;
    }
    return res;
}

int main()
{
    int n, b;
    cin >> n >> b;
    cout << solve(n, b) << endl;
    return 0;
}