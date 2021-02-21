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

static int dia = 0;

int calDiaReturnHeight(Node *node)
{
    int dch = -1;
    int sdch = -1;

    for (Node *child : node->children)
    {
        int ch = calDiaReturnHeight(child);
        if (ch > dch)
        {
            sdch = dch;
            dch = ch;
        }
        else if (ch > sdch)
        {
            sdch = ch;
        }
    }

    int cand = dch + sdch + 2;
    if (cand > dia)
    {
        dia = cand;
    }

    return dch + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    calDiaReturnHeight(root);
    cout << dia << endl;

    return 0;
}