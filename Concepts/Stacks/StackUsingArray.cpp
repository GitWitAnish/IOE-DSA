#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of stack

class Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Points to top element

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed to stack\n";
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop\n";
        } else {
            cout << arr[top] << " popped from stack\n";
            top--;
        }
    }

    // Peek (Top element)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.display();

    return 0;
}
