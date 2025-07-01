// Creation of linked list 

#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
  Node* head;

public:
  LinkedList() : head(NULL) {}
};

int main() {
  LinkedList list;
  return 0;
}
