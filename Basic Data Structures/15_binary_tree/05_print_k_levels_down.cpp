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

vector<Node *> path;

bool find(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data == data)
    {
        path.push_back(node);
        return true;
    }

    bool filc = find(node->left, data);
    if (filc)
    {
        path.push_back(node);
        return true;
    }

    bool firc = find(node->right, data);
    if (firc)
    {
        path.push_back(node);
        return true;
    }

    return false;
}

void printKLevelsDown(Node *node, int k, Node *block)
{
    if (node == NULL || k < 0 || node == block)
    {
        return;
    }
    if (k == 0)
    {
        cout << node->data << '\n';
    }
    printKLevelsDown(node->left, k - 1, block);
    printKLevelsDown(node->right, k - 1, block);
}

void printKNodesFar(Node *node, int data, int k)
{
    find(node, data);
    for (int i = 0; i < path.size(); i++)
    {
        Node *blocker = (i != 0) ? path[i - 1] : NULL;
        printKLevelsDown(path[i], k - i, blocker);
    }
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

    int data, k;
    cin >> data >> k;

    Node *root = construct(arr);
    printKNodesFar(root, data, k);

    return 0;
}