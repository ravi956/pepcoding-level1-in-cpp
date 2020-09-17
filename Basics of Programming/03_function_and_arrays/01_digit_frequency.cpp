#include <iostream>
using namespace std;

int solve(int n, int d)
{
    int count = 0;
    do
    {
        if (n % 10 == d)
            count++;
        n /= 10;
    } while (n != 0);
    return count;
}

int main()
{
    int n, d;
    cin >> n >> d;
    cout << solve(n, d) << endl;
    return 0;
}