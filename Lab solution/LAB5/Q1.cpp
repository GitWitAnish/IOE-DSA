// Insertion of single linked list 

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

  void insertAtHead(int val) {
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
  }

  void insertAtEnd(int val) {
    Node* newnode = new Node(val);
    if (!head) {
      head = newnode;
      return;
    }
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newnode;
  }

  void insertAtPosition(int val, int position) {
    if (position <= 1 || !head) {
      insertAtHead(val);
      return;
    }
    Node* newnode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next; i++) {
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }

  void display() {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList list;
  list.insertAtEnd(10);
  list.insertAtEnd(20);
  list.insertAtHead(5);
  list.insertAtPosition(15, 3);
  cout << "Linked list after insertions: ";
  list.display();
  return 0;
}
