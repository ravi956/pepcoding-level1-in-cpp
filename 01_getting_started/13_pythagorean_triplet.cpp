#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    a *= a;
    b *= b;
    c *= c;
    if ((a == b + c) || (b == a + c) || (c == a + b))
        cout << "true";
    else
        cout << "false";
    return 0;
}
