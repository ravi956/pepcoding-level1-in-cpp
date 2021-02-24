#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> data;

    void upheapify(int i)
    {
        if (i == 0)
            return;

        int pi = (i - 1) / 2;
        if (data[i] < data[pi])
        {
            swap(data[i], data[pi]);
            upheapify(pi);
        }
    }

    void downheapify(int pi)
    {
        int mini = pi;
        int li = 2 * pi + 1;
        if (li < data.size() && data[li] < data[mini])
            mini = li;

        int ri = 2 * pi + 2;
        if (ri < data.size() && data[ri] < data[mini])
            mini = ri;

        if (mini != pi)
        {
            swap(data[pi], data[mini]);
            downheapify(mini);
        }
    }

public:
    void add(int val)
    {
        data.push_back(val);
        upheapify(data.size() - 1);
    }

    int remove()
    {
        if (this->size() == 0)
        {
            cout << "Underflow\n";
            return -1;
        }
        swap(data[0], data.back());
        int val = data.back();
        data.pop_back();
        downheapify(0);
        return val;
    }

    int peek()
    {
        if (this->size() == 0)
        {
            cout << "Underflow\n";
            return -1;
        }
        return data[0];
    }

    int size()
    {
        return data.size();
    }
};

int main()
{
    PriorityQueue qu;

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