// Creation of doubly linked list


#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* prev;
  Node* next;

  Node(int num) : data(num), prev(NULL), next(NULL) {}
};

int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);

  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;

  return 0;
}
