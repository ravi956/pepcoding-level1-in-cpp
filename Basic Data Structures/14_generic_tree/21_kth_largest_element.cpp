#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << endl;

    for (Node *child : node->children)
        display(child);
}

Node *construct(vector<int> &arr)
{
    Node *root = NULL;
    stack<Node *> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node();
            t->data = arr[i];

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

static int cl;
static int fl;

void ceilAndFloor(Node *node, int data)
{
    if (node->data > data)
        cl = min(cl, node->data);
    if (node->data < data)
        fl = max(fl, node->data);

    for (Node *child : node->children)
        ceilAndFloor(child, data);
}

int kthLargest(Node *node, int k)
{
    // write your code here
    int largest = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        fl = INT_MIN;
        ceilAndFloor(node, largest);
        largest = fl;
    }
    return largest;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    Node *root = construct(arr);
    int kth_largest = kthLargest(root, k);
    cout << kth_largest << endl;

    return 0;
}