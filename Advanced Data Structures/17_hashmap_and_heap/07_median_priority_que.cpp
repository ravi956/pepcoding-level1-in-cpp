#include <bits/stdc++.h>
using namespace std;

class MedianPriorityQueue
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void add(int val)
    {
        if (right.size() > 0 && val > right.top())
            right.push(val);
        else
            left.push(val);

        if (left.size() - right.size() == 2)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() - left.size() == 2)
        {
            left.push(right.top());
            right.pop();
        }
    }

    int remove()
    {
        if (left.size() == 0 && right.size() == 0)
        {
            cout << "Underflow\n";
            return -1;
        }
        else if (left.size() >= right.size())
        {
            int val = left.top();
            left.pop();
            return val;
        }
        else
        {
            int val = right.top();
            right.pop();
            return val;
        }
    }

    int peek()
    {
        if (left.size() == 0 && right.size() == 0)
        {
            cout << "Underflow\n";
            return -1;
        }
        else if (left.size() >= right.size())
        {
            return left.top();
        }
        else
        {
            return right.top();
        }
    }

    int size()
    {
        return left.size() + right.size();
    }
};

int main()
{
    MedianPriorityQueue qu;

    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "add")
        {
            int val;
            cin >> val;
            qu.add(val);
        }
        else if (str == "remove")
        {
            int val = qu.remove();
            if (val != -1)
                cout << val << "\n";
        }
        else if (str == "peek")
        {
            int val = qu.peek();
            if (val != -1)
                cout << val << "\n";
        }
        else if (str == "size")
        {
            cout << qu.size() << "\n";
        }

        cin >> str;
    }

    return 0;
}