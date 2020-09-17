#include <iostream>
using namespace std;

int solve1(int n, int b)
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
int solve2(int n, int b)
{
    int res = 0;
    int mult = 1;
    while (n != 0)
    {
        res += (n % b) * mult;
        mult *= 10;
        n /= b;
    }
    return res;
}

int main()
{
    int n, b1, b2;
    cin >> n >> b1 >> b2;
    int decimal = solve1(n, b1);
    int result = solve2(decimal, b2);
    cout << result << endl;
    return 0;
}