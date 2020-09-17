#include <iostream>
using namespace std;

int solve(int b, int n1, int n2)
{
    int sum = 0;
    int carry = 0;
    int mult = 1;
    while (n1 > 0 || n2 > 0 || carry > 0)
    {
        int d1 = n1 % 10;
        int d2 = n2 % 10;
        int c = (d1 + d2 + carry);
        sum += (c % b) * mult;
        carry = c / b;
        mult *= 10;
        n1 /= 10;
        n2 /= 10;
    }
    return sum;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << solve(b, n1, n2) << endl;
    return 0;
}

//It can also be solved by converting into decimal, performing sum and then converting
//again into the given base