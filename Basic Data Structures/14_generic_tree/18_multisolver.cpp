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

static int size;
static int mini;
static int maxi;
static int height;

void multisolver(Node *node, int depth)
{
    size++;
    mini = min(mini, node->data);
    maxi = max(maxi, node->data);
    height = max(height, depth);
    for (Node *child : node->children)
        multisolver(child, depth + 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    size = 0;
    mini = INT_MAX;
    maxi = INT_MIN;
    height = 0;
    multisolver(root, 0);
    cout << (size) << endl;
    cout << (mini) << endl;
    cout << (maxi) << endl;
    cout << (height) << endl;

    return 0;
}