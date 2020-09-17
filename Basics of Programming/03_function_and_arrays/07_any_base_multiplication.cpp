#include <iostream>
using namespace std;

int sourceBaseToDecimal(int n, int b1)
{
    int res = 0;
    int mult = 1;
    while (n != 0)
    {
        res += (n % 10) * mult;
        mult *= b1;
        n /= 10;
    }
    return res;
}

int decimalToDestBase(int n, int b2)
{
    int res = 0;
    int mult = 1;
    while (n != 0)
    {
        res += (n % b2) * mult;
        mult *= 10;
        n /= b2;
    }
    return res;
}

int getProduct(int b, int n1, int n2)
{
    int m1 = sourceBaseToDecimal(n1, b);
    int m2 = sourceBaseToDecimal(n2, b);
    int product = m1 * m2;
    return decimalToDestBase(product, b);
}

int main()
{

    int b, n1, n2;
    cin >> b >> n1 >> n2;

    int d = getProduct(b, n1, n2);
    cout << d << endl;
    return 0;
}