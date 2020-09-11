#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int space = 2 * n - 3;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << "\t";
        for (int j = 1; j <= space; j++)
            cout << "\t";
        for (int j = i; j >= 1; j--)
            if (j != n)
                cout << j << "\t";
        cout << endl;
        space -= 2;
    }
    return 0;
}
