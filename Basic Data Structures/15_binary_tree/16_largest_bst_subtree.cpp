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

struct BSTPair
{
    bool isBST;
    int mini;
    int maxi;
    Node *lbstroot;
    int lbstsize;
};

BSTPair *isBST(Node *node)
{
    if (node == NULL)
    {
        BSTPair *bp = new BSTPair();
        bp->isBST = true;
        bp->mini = INT_MAX;
        bp->maxi = INT_MIN;
        bp->lbstroot = NULL;
        bp->lbstsize = 0;
        return bp;
    }

    BSTPair *lp = isBST(node->left);
    BSTPair *rp = isBST(node->right);

    BSTPair *mp = new BSTPair();
    mp->isBST = lp->isBST && rp->isBST && (node->data >= lp->maxi && node->data <= rp->mini);
    if (mp->isBST)
    {
        mp->lbstsize = lp->lbstsize + rp->lbstsize + 1;
        mp->lbstroot = node;
    }
    else if (lp->lbstsize > rp->lbstsize)
    {
        mp->lbstsize = lp->lbstsize;
        mp->lbstroot = lp->lbstroot;
    }
    else
    {
        mp->lbstsize = rp->lbstsize;
        mp->lbstroot = rp->lbstroot;
    }
    mp->mini = min(node->data, min(lp->mini, rp->mini));
    mp->maxi = max(node->data, max(lp->maxi, rp->maxi));
    return mp;
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

    Node *root = construct(arr);

    BSTPair *result = isBST(root);
    cout << result->lbstroot->data << "@" << result->lbstsize;

    return 0;
}