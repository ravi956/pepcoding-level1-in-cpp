#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int space = n / 2;
    int star = 1;
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        int add = 0;
        for (int j = 1; j <= space; j++)
            cout << "\t";
        for (int j = 1; j <= star; j++)
        {
            cout << (start + add) << "\t";
            if (j <= star / 2)
                add++;
            else
                add--;
        }
        if (i <= n / 2)
        {
            space--;
            star += 2;
            start++;
        }
        else
        {
            space++;
            star -= 2;
            start--;
        }
        cout << endl;
    }
    return 0;
}
