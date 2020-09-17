#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int space = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= space; j++)
            cout << "\t";
        space--;
        cout << "*\n";
    }
    return 0;
}