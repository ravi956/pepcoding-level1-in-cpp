#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head, *tail;
    int size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addLast(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList list;

    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "addLast")
        {
            int val;
            cin >> val;
            list.addLast(val);
        }
        else if (str == "size")
            cout << list.getSize() << "\n";
        else
            list.display();
        cin >> str;
    }

    return 0;
}