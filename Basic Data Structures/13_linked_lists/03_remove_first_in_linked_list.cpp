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

    void removeFirst()
    {
        if (size == 0)
        {
            cout << "List is empty\n";
        }
        else if (size == 1)
        {
            Node *temp = head;
            head = tail = NULL;
            delete (temp);
            size--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
            size--;
        }
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
        else if (str == "display")
            list.display();
        else if (str == "removeFirst")
            list.removeFirst();
        cin >> str;
    }

    return 0;
}