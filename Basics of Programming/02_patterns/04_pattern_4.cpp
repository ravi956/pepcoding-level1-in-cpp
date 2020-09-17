#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = n - i; j > 0; j--)
            cout << "\t";
        for (int j = 1; j <= i; j++)
            cout << "*\t";
        cout << endl;
    }
    return 0;
}