#include <iostream>
using namespace std;

class Stack {
private:
  int top;
  int *arr;
  int capacity;

public:
  Stack(int size) {
    top = -1;
    capacity = size;
    arr = new int[size];
  }

  void push(int data) {
    if (top + 1 == capacity) {
      cout << "Stack overflow!" << endl;
      return;
    }
    arr[++top] = data;
  }

  int pop() {
    if (top == -1) {
      cout << "Stack underflow!" << endl;
      return -1;
    }
    return arr[top--];
  }
};

int main() {
  Stack s(5);
  s.push(10);
  s.push(20);
  cout << "Popped: " << s.pop() << endl;
  cout << "Popped: " << s.pop() << endl;
  cout << "Popped: " << s.pop() << endl; 
}
