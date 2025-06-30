// Enqueue and Dequeue operations in a Queue using an array

// Time Complexity: O(n)

#include <iostream>
using namespace std;

#define SIZE 2

int A[SIZE];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

void enqueue(int val)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    A[rear] = val;
    cout << "Enqueued Value : " << val << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            cout << "Dequeued Value : " << A[front] << endl;
            front++;
        }
    }
}

void displayQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    dequeue();
    enqueue(2);
    enqueue(4);
    enqueue(6);
    dequeue();
    displayQueue();
    return 0;
}