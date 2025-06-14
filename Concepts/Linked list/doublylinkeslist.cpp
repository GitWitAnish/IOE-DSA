
#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *prev;
  Node *next;
  Node(int num) : data(num), prev(NULL), next(NULL) {}
};
void forwardTraversal(Node *head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " <-> ";
    curr = curr->next;
  }
  cout << endl;
}
void backwardTraversal(Node *tail)
{
  Node *curr = tail;
  while (curr != NULL)
  {
    cout << curr->data << " <-> ";
    curr = curr->prev;
  }
  cout << endl;
}
int findLength(Node *head)
{
  int count = 0;
  for (Node *curr = head; curr != NULL; curr = curr->next)
    count++;
  return count;
}
Node *insertAtHead(Node *head, int data)
{
  Node *newnode = new Node(data);
  newnode->next = head;
  if (head != NULL)
    head->prev = newnode;
  return newnode;
}
int main()
{
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;
  cout << "Forward Traversal:" << endl;
  forwardTraversal(head);
  cout << "Backward Traversal:" << endl;
  backwardTraversal(third);
  cout << "Count length:" << findLength(head) << endl;
  Node *newhead = insertAtHead(head, 20);
  cout << "InsertAtHead" << endl;
  forwardTraversal(newhead);
  return 0;
}