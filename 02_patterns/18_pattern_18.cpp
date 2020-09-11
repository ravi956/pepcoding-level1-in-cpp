#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int os = 0;
    int star = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= os; j++)
            cout << "\t";
        for (int j = 1; j <= star; j++)
        {
            if (j > 1 && j < star && i > 1 && i <= n / 2)
                cout << "\t";
            else
                cout << "*\t";
        }
        if (i <= n / 2)
        {
            os++;
            star -= 2;
        }
        else
        {
            os--;
            star += 2;
        }
        cout << endl;
    }
    return 0;
}