#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;

    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (d == arr[mid])
        {
            cout << d << "\n"
                 << d;
            break;
        }
        else if (d < arr[mid])
        {
            if (d > arr[mid - 1])
            {
                cout << arr[mid] << "\n"
                     << arr[mid - 1];
                break;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (d < arr[mid + 1])
            {
                cout << arr[mid + 1] << "\n"
                     << arr[mid];
                break;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return 0;
}