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

    int first = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (d > arr[mid])
        {
            low = mid + 1;
        }
        else if (d < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != d)
            {
                first = mid;
                break;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    int last = -1;
    low = first;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (d > arr[mid])
        {
            low = mid + 1;
        }
        else if (d < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            if (mid == n - 1 || arr[mid + 1] != d)
            {
                last = mid;
                break;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    cout << first << "\n"
         << last;
    return 0;
}