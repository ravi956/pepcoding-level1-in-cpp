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

static Node *nodeMax = NULL;
static int maxSum = INT_MIN;

int maxSumSubtree(Node *node)
{
    int sum = 0;
    for (Node *child : node->children)
        sum += maxSumSubtree(child);

    sum += node->data;
    if (sum > maxSum)
    {
        maxSum = sum;
        nodeMax = node;
    }
    return sum;
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
    maxSumSubtree(root);
    cout << nodeMax->data << "@" << maxSum << endl;

    return 0;
}