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

int size(Node *node)
{
    if (node == NULL)
        return 0;

    return 1 + size(node->left) + size(node->right);
}

int sum(Node *node)
{
    if (node == NULL)
        return 0;

    return node->data + sum(node->left) + sum(node->right);
}

int maximum(Node *node)
{
    if (node == NULL)
        return INT_MIN;

    return max(node->data, maximum(node->right));
}

int minimum(Node *node)
{
    if (node == NULL)
        return INT_MAX;

    return min(node->data, minimum(node->left));
}

bool find(Node *node, int data)
{
    if (node == NULL)
        return false;

    if (data == node->data)
        return true;

    if (data < node->data)
        return find(node->left, data);
    else
        return find(node->right, data);
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

    int data;
    cin >> data;

    Node *root = construct(arr);

    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << maximum(root) << endl;
    cout << minimum(root) << endl;
    if (find(root, data))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}