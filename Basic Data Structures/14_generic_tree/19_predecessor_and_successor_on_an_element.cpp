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

static Node *predecessor;
static Node *successor;
static int state;

void predecessorAndSuccessor(Node *node, int data)
{
    // write your code here
    if (state == 0)
    {
        if (node->data == data)
        {
            state = 1;
        }
        else
        {
            predecessor = node;
        }
    }
    else if (state == 1)
    {
        successor = node;
        state = 2;
    }

    for (Node *child : node->children)
    {
        predecessorAndSuccessor(child, data);
    }
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
    predecessor = NULL;
    successor = NULL;
    state = 0;
    predecessorAndSuccessor(root, data);
    if (predecessor == NULL)
    {
        cout << "Predecessor = Not found" << endl;
    }
    else
    {
        cout << "Predecessor = " << predecessor->data << endl;
    }

    if (successor == NULL)
    {
        cout << "Successor = Not found" << endl;
    }
    else
    {
        cout << "Successor = " << successor->data << endl;
    }

    return 0;
}