#include <iostream>
using namespace std;

// Node class remains same
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// CircularLinkedList class
class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertAtEnd(int val)
    {
        Node *newnode = new Node(val);

        if (!head)
        {
            head = newnode;
            newnode->next = head;  // circular link
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    void insertAtHead(int val)
    {
        Node *newnode = new Node(val);

        if (!head)
        {
            head = newnode;
            newnode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    void deleteFromHead()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head) // only one node
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node *todelete = head;
        temp->next = head->next;
        head = head->next;
        delete todelete;
    }

    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *todelete = temp->next;
        temp->next = head;
        delete todelete;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(head)" << endl;
    }
};

int main()
{
    CircularLinkedList clist;
    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtEnd(30);
    clist.insertAtHead(5);
    cout << "Circular Linked List after insertions: ";
    clist.display();

    clist.deleteFromHead();
    cout << "After deleting from head: ";
    clist.display();

    clist.deleteFromEnd();
    cout << "After deleting from end: ";
    clist.display();

    return 0;
}
