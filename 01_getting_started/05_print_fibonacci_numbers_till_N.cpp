#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 0;
    else if (n == 2)
        cout << "0 1";
    else
    {
        int a = 0;
        int b = 1;
        cout << "0 1 ";
        for (int i = 3; i <= n; i++)
        {
            int c = b + a;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
    return 0;
}