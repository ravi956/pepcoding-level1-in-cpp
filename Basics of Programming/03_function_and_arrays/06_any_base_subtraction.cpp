#include <iostream>
using namespace std;

int solve(int b, int n1, int n2)
{
    int difference = 0;
    int carry = 0;
    int mult = 1;
    while (n1 > 0 || n2 > 0)
    {
        int d1 = n1 % 10;
        int d2 = n2 % 10;
        int c = (d2 - d1 + carry);
        if (c < 0)
        {
            c += b;
            carry = -1;
        }
        else
            carry = 0;
        difference += c * mult;
        mult *= 10;
        n1 /= 10;
        n2 /= 10;
    }
    return difference;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << solve(b, n1, n2) << endl;
    return 0;
}

//It can also be solved by converting into decimal, performing diff. and then converting
//again into the given base