#include <iostream>
using namespace std;

int main()
{
    int low, high;
    cin >> low >> high;
    for (int i = low; i <= high; i++)
    {
        int flag = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << i << " ";
    }
    return 0;
}