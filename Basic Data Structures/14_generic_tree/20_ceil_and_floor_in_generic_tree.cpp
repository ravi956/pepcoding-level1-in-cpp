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

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int data;
    cin >> data;

    Node *root = construct(arr);
    cl = INT_MAX;
    fl = INT_MIN;
    ceilAndFloor(root, data);
    cout << "CEIL = " << cl << endl;
    cout << "FLOOR = " << fl << endl;

    return 0;
}