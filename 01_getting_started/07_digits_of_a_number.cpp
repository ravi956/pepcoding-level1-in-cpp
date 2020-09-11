#include <iostream>
using namespace std;

void printDigits(int n)
{
    if (n < 10)
    {
        cout << n << " ";
        return;
    }
    int lastDigit = n % 10;
    printDigits(n / 10);
    cout << lastDigit << " ";
}

int main()
{
    int n;
    cin >> n;
    printDigits(n);
    return 0;
}