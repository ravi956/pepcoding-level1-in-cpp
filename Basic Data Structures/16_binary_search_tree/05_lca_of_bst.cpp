#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

struct Pair
{
    Node *node;
    int state;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0], NULL, NULL);
    Pair *rtp = new Pair(root, 1);

    stack<Pair *> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = new Node(arr[idx], NULL, NULL);
                st.push(new Pair(top->node->left, 1));
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = new Node(arr[idx], NULL, NULL);
                st.push(new Pair(top->node->right, 1));
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void display(Node *node)
{
    if (node == NULL)
        return;

    string str = "";
    str += (node->left == NULL) ? "." : to_string(node->left->data);
    str += " <- " + to_string(node->data) + " -> ";
    str += (node->right == NULL) ? "." : to_string(node->right->data);
    cout << str << "\n";

    display(node->left);
    display(node->right);
}

int maximum(Node *node)
{
    if (node->right != NULL)
    {
        return maximum(node->right);
    }

    return node->data;
}

int lca(Node *node, int d1, int d2)
{
    if (d1 < node->data && d2 < node->data)
        return lca(node->left, d1, d2);
    else if (d1 > node->data && d2 > node->data)
        return lca(node->right, d1, d2);
    else
        return node->data;
}

int main()
{
    int n;
    cin >> n;
    string str;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "n")
            arr[i] = -1;
        else
        {
            int temp = stoi(str);
            arr[i] = temp;
        }
    }

    int d1, d2;
    cin >> d1 >> d2;

    Node *root = construct(arr);
    cout << lca(root, d1, d2) << "\n";

    return 0;
}