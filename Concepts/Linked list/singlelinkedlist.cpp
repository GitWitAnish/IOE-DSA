#include <iostream>
using namespace std;
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
class LinkedList
{
  Node *head;

public:
  LinkedList() : head(NULL) {}
  void insertAtHead(int val)
  {
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = head;
    head = newnode;
  }
  void insertAtEnd(int val)
  {
    Node *newnode = new Node(val);
    newnode->next = NULL;
    if (head == NULL)
    {
      head = newnode;
      return;
    }
    Node *temp = head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
  void insertAtPosition(int val, int position)
  {
    if (position < 1)
    {
      cout << "Position should be more or equal to 1" << endl;
      return;
    }
    if (position == 1)
    {
      insertAtHead(val);
      return;
    }
    Node *newnode = new Node();
    newnode->data = val;
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; i++)
    {
      temp = temp->next;
    }
    if (!temp)
    {
      cout << "Position out of the range" << endl;
      delete newnode;
      return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
  void deleteFromHead()
  {
    if (!head)
    {
      cout << "Linked list is empty" << endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  void deleteFromEnd()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }
    if (!head->next)
    {
      delete head;
      head = NULL;
      return;
    }
    Node *temp = head;
    while (temp->next->next)
    {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
  }
  void deleteFromPosition(int position)
  {
    if (position < 1)
    {
      cout << "Position should be more or equal to 1" << endl;
      return;
    }
    if (position == 1)
    {
      deleteFromHead();
      return;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; i++)
    {
      temp = temp->next;
    }
    if (!temp || !temp->next)
    {
      cout << "Position out of range" << endl;
      return;
    }
    Node *deletethis = temp->next;
    temp->next = temp->next->next;
    delete deletethis;
  }
  void display()
  {
    if (!head)
    {
      cout << "List is empty";
      return;
    }
    Node *temp = head;
    while (temp)
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
int main()
{
  LinkedList list1;
  list1.insertAtEnd(10);
  list1.insertAtEnd(20);
  list1.insertAtHead(5);
  list1.insertAtPosition(15, 3);
  cout << "Linked list after insertions: ";
  list1.display();
  list1.deleteFromHead();
  cout << "Linked list after deleting from beginning: ";
  list1.display();
  list1.deleteFromEnd();
  cout << "Linked list after deleting from end: ";
  list1.display();
  list1.deleteFromPosition(2);
  cout << "Linked list after deleting from position 2: ";
  list1.display();
  return 0;
}